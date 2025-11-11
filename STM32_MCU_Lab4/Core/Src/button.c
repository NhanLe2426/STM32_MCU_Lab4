/*
 * button.c
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

/* Includes */
#include "button.h"

/* Variables */
GPIO_TypeDef* BTN_GPIO[MAX_BUTTON] = {
		BUTTON_1_GPIO_Port,
		BUTTON_2_GPIO_Port,
		BUTTON_3_GPIO_Port
};

uint16_t BTN_Pin[MAX_BUTTON] = {
		BUTTON_1_Pin,
		BUTTON_2_Pin,
		BUTTON_3_Pin
};

int button_flag[MAX_BUTTON] = { 0 };
int button_long_flag[MAX_BUTTON] = { 0 };

// Two debounce buffer
int buffer0[MAX_BUTTON];
int buffer1[MAX_BUTTON];

// Current stable state of button
int currState[MAX_BUTTON];

// Previous stable state of button
int prevState[MAX_BUTTON];

// Time out counter for pressed and hold case
int timeOutCounter[MAX_BUTTON];

/* Functions */

/**
 * @brief	Initial values for input button processing
 * @param	None
 * @retval	None
 */
void inputReadingInit(void) {
	for (int i = 0; i < MAX_BUTTON; i++) {
		buffer0[i] = NORMAL_STATE;
		buffer1[i] = NORMAL_STATE;
		currState[i] = NORMAL_STATE;
		prevState[i] = NORMAL_STATE;
		timeOutCounter[i] = TIME_OUT;
	}
}

/**
 * @brief	Check if the index button is pressed or not
 * @param	index : The index of the current button
 * @retval	1 if the button is pressed (flag = 1) or 0 if it is not (flag = 0)
 */
int isButtonPressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

/**
 * @brief	Check if the index button is pressed and hold (for more than 3s) or not
 * @param	index : The index of current button
 * @retval	1 if the button is pressed and hold (flag = 1) or 0 if it is not (flag = 0)
 */
int isButtonLongPressed(int index) {
	if (button_long_flag[index] == 1) {
		button_long_flag[index] = 0;
		return 1;
	}
	return 0;
}

/**
 * @brief	Get the input from buttons and debounce processing
 * @param	None
 * @retval	None
 */
void getKeyInput(void) {
	for (int i = 0; i < MAX_BUTTON; i++) {
		buffer0[i] = buffer1[i];
		buffer1[i] = currState[i];
		currState[i] = HAL_GPIO_ReadPin(BTN_GPIO[i], BTN_Pin[i]);

		if ((buffer0[i] == buffer1[i]) && (buffer1[i] == currState[i])) {
			if (prevState[i] != currState[i]) {
				prevState[i] = currState[i];

				// PRESSED
				if (currState[i] == PRESSED_STATE) {
					button_flag[i] = 1;
					timeOutCounter[i] = TIME_OUT;
				}
			}
			else {
				timeOutCounter[i]--;
				if (timeOutCounter[i] <= 0) {
					timeOutCounter[i] = TIME_OUT;
					// PRESSSED AND HOLD
					if (prevState[i] == PRESSED_STATE) {
						button_long_flag[i] = 1;
					}
					// prevState[i] = NORMAL_STATE;
				}
			}
		}
	}
}
