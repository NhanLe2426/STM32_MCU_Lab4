/*
 * fsm_automatic.c
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

/* Includes */
#include "fsm_automatic.h"

/* Variables */

/* Functions */

/**
 * @brief	Initialize timer and led buffer array before switching to Manual Mode (Init State)
 * @param	None
 * @retval	None
 */
void initManualMode(void) {
	setTimer(3, 500);
	updateLedBuffer(0, 0);
	updateLedBuffer(1, 0);
	updateLedBuffer(2, 0);
	updateLedBuffer(3, 0);
}

/**
 * @brief	Initialize timer and led buffer array before switching to Config Mode (Init State)
 * @param	None
 * @retval	None
 */
void initConfigMode(void) {
	setTimer(3, 500);
	updateLedBuffer(0, 0);
	updateLedBuffer(1, 1);
	updateLedBuffer(2, 0);
	updateLedBuffer(3, 1);
}

/**
 * @brief	Run the FSM in automatic mode
 * @param	None
 * @retval	None
 */
void FSM_Automatic_Run(void) {
	switch (status) {
	case INIT_AUTO:
		setAllRedLED(OFF);
		setAllYellowLED(OFF);
		setAllGreenLED(OFF);

		status = RED_GREEN;
		setTimer(0, 5000);
		setTimer(1, 1000 * redDuration);
		setTimer(2, 1000 * greenDuration);

		button_flag[0] = 0;
		button_flag[1] = 0;
		button_flag[2] = 0;

		updateLedBuffer(0, (redDuration) / 10);
		updateLedBuffer(1, (redDuration) % 10);
		updateLedBuffer(2, (greenDuration) / 10);
		updateLedBuffer(3, (greenDuration) % 10);
		break;

	case RED_GREEN:
		setLightWay1(RESET, SET, SET);
		setLightWay2(SET, SET, RESET);

		if (isTimerExpired(2) == 1) {
			status = RED_YELLOW;
			setTimer(2, 1000 * yellowDuration);

			updateLedBuffer(2, (yellowDuration) / 10);
			updateLedBuffer(3, (yellowDuration) % 10);
		}

		// Press button 1 to access CONFIG MODE
		if (isButtonPressed(0) == 1) {
			status = INIT_CONFIG;
			initConfigMode();
		}

		// Press button 3 to access MANUAL MODE
		if (isButtonPressed(2) == 1) {
			status = INIT_MAN;
			initManualMode();
		}
		break;

	case RED_YELLOW:
		setLightWay1(RESET, SET, SET);
		setLightWay2(SET, RESET, SET);

		if (isTimerExpired(2) == 1) {
			status = GREEN_RED;
			setTimer(1, 1000 * greenDuration);
			setTimer(2, 1000 * redDuration);

			updateLedBuffer(0, (greenDuration) / 10);
			updateLedBuffer(1, (greenDuration) % 10);
			updateLedBuffer(2, (redDuration) / 10);
			updateLedBuffer(3, (redDuration) % 10);
		}

		// Press button 1 to access CONFIG MODE
		if (isButtonPressed(0) == 1) {
			status = INIT_CONFIG;
			initConfigMode();
		}

		// Press button 3 to access MANUAL MODE
		if (isButtonPressed(2) == 1) {
			status = INIT_MAN;
			initManualMode();
		}
		break;

	case GREEN_RED:
		setLightWay1(SET, SET, RESET);
		setLightWay2(RESET, SET, SET);

		if (isTimerExpired(1) == 1) {
			status = YELLOW_RED;
			setTimer(1, 1000 * yellowDuration);

			updateLedBuffer(0, (yellowDuration) / 10);
			updateLedBuffer(1, (yellowDuration) % 10);
		}

		// Press button 1 to access CONFIG MODE
		if (isButtonPressed(0) == 1) {
			status = INIT_CONFIG;
			initConfigMode();
		}

		// Press button 3 to access MANUAL MODE
		if (isButtonPressed(2) == 1) {
			status = INIT_MAN;
			initManualMode();
		}
		break;

	case YELLOW_RED:
		setLightWay1(SET, RESET, SET);
		setLightWay2(RESET, SET, SET);

		if (isTimerExpired(1) == 1) {
			status = RED_GREEN;
			setTimer(1, 1000 * redDuration);
			setTimer(2, 1000 * greenDuration);

			updateLedBuffer(0, (redDuration) / 10);
			updateLedBuffer(1, (redDuration) % 10);
			updateLedBuffer(2, (greenDuration) / 10);
			updateLedBuffer(3, (greenDuration) % 10);
		}

		// Press button 1 to access CONFIG MODE
		if (isButtonPressed(0) == 1) {
			status = INIT_CONFIG;
			initConfigMode();
		}

		// Press button 3 to access MANUAL MODE
		if (isButtonPressed(2) == 1) {
			status = INIT_MAN;
			initManualMode();
		}
		break;

	default:
		break;
	}

	if ((status == 2) || (status == 3) || (status == 4) || (status == 5)) {
		// Scan 4 7-segment LEDs with the frequency of 0.5Hz
		if (isTimerExpired(3) == 1) {
			update7SEG(index_led++);
			index_led = index_led % 4;
			setTimer(3, 500);
		}

		// Count down the duration for displaying on 7-segment LEDs
		if (isTimerExpired(4) == 1) {
			updateLedBuffer(1, led_buffer[1] - 1);
			updateLedBuffer(3, led_buffer[3] - 1);
			setTimer(4, 1000);
		}
	}
}
