/*
 * fsm_config.c
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

/* Includes */
#include "fsm_config.h"

/* Variables */

int inc_RedDuration;
int inc_YelDuration;
int inc_GrnDuration;

/* Functions */

/**
 * @brief	Run the FSM in configuration mode
 * @param	None
 * @retval	None
 */
void FSM_Config_Run(void) {
	switch (status) {
	case INIT_CONFIG:
		inc_RedDuration = 0;
		inc_YelDuration = 0;
		inc_GrnDuration = 0;

		status = RED_CONFIG;

		setAllRedLED(OFF);
		setAllYellowLED(OFF);
		setAllGreenLED(OFF);

		setTimer(3, 500);
		setTimer(4, 500);

		updateLedBuffer(0, redDuration / 10);
		updateLedBuffer(1, redDuration % 10);
		updateLedBuffer(2, 0);
		updateLedBuffer(3, 2);
		break;

	case RED_CONFIG:
		// Press button 1 to access YELLOW_CONFIG mode
		if (isButtonPressed(0) == 1) {
			status = YELLOW_CONFIG;

			setAllRedLED(OFF);
			setAllYellowLED(ON);

			updateLedBuffer(0, yellowDuration / 10);
			updateLedBuffer(1, yellowDuration % 10);
			updateLedBuffer(2, 0);
			updateLedBuffer(3, 3);
		}

		if (isButtonPressed(1) == 1) {
			inc_RedDuration++;
			if (inc_RedDuration + redDuration >= 100) {
				inc_RedDuration = 0 - redDuration;
			}

			updateLedBuffer(0, (inc_RedDuration + redDuration) / 10);
			updateLedBuffer(1, (inc_RedDuration + redDuration) % 10);
		}

		if (isButtonPressed(2) == 1) {
			redDuration = redDuration + inc_RedDuration;
			inc_RedDuration = 0;

			updateLedBuffer(0, redDuration / 10);
			updateLedBuffer(1, redDuration % 10);
		}

		if (isTimerExpired(4) == 1) {
			HAL_GPIO_TogglePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin);
			HAL_GPIO_TogglePin(RED_LED_2_GPIO_Port, RED_LED_2_Pin);

			setTimer(4, 500);
		}
		break;

	case YELLOW_CONFIG:
		// Press button 1 to access GREEN_CONFIG mode
		if (isButtonPressed(0) == 1) {
			status = GREEN_CONFIG;

			setAllYellowLED(OFF);
			setAllGreenLED(ON);

			updateLedBuffer(0, greenDuration / 10);
			updateLedBuffer(1, greenDuration % 10);
			updateLedBuffer(2, 0);
			updateLedBuffer(3, 4);
		}

		if (isButtonPressed(1) == 1) {
			inc_YelDuration++;
			if (inc_YelDuration + yellowDuration >= 100) {
				inc_YelDuration = 0 - yellowDuration;
			}

			updateLedBuffer(0, (inc_YelDuration + yellowDuration) / 10);
			updateLedBuffer(1, (inc_YelDuration + yellowDuration) % 10);
		}

		if (isButtonPressed(2) == 1) {
			yellowDuration = yellowDuration + inc_YelDuration;
			inc_YelDuration = 0;

			updateLedBuffer(0, yellowDuration / 10);
			updateLedBuffer(1, yellowDuration % 10);
		}

		if (isTimerExpired(4) == 1) {
			HAL_GPIO_TogglePin(YEL_LED_1_GPIO_Port, YEL_LED_1_Pin);
			HAL_GPIO_TogglePin(YEL_LED_2_GPIO_Port, YEL_LED_2_Pin);

			setTimer(4, 500);
		}
		break;

	case GREEN_CONFIG:
		// Press button 1 to return to AUTO MODE
		if (isButtonPressed(0) == 1) {
			setAllGreenLED(OFF);

			status = INIT_AUTO;
		}

		if (isButtonPressed(1) == 1) {
			inc_GrnDuration++;
			if (inc_GrnDuration + greenDuration >= 100) {
				inc_GrnDuration = 0 - greenDuration;
			}

			updateLedBuffer(0, (inc_GrnDuration + greenDuration) / 10);
			updateLedBuffer(1, (inc_GrnDuration + greenDuration) % 10);
		}

		if (isButtonPressed(2) == 1) {
			greenDuration = greenDuration + inc_GrnDuration;
			inc_GrnDuration = 0;

			updateLedBuffer(0, greenDuration / 10);
			updateLedBuffer(1, greenDuration % 10);
		}

		if (isTimerExpired(4) == 1) {
			HAL_GPIO_TogglePin(GRN_LED_1_GPIO_Port, GRN_LED_1_Pin);
			HAL_GPIO_TogglePin(GRN_LED_2_GPIO_Port, GRN_LED_2_Pin);

			setTimer(4, 500);
		}
		break;

	default:
		break;
	}

	// Scan 4 7-segment LEDs with the frequency of 0.5Hz
	if (isTimerExpired(3) == 1) {
		update7SEG(index_led++);
		index_led = index_led % 4;
		setTimer(3, 500);
	}
}
