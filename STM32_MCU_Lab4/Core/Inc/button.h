/*
 * button.h
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

/* Includes */
#include "main.h"

/* Defines */
#define NORMAL_STATE	GPIO_PIN_SET		// 1
#define PRESSED_STATE	GPIO_PIN_RESET		// 0

// Number of Buttons
#define MAX_BUTTON		3

// Time Out for Key Press
#define TIME_OUT		300

/* Variables */
extern int button_flag[MAX_BUTTON];
extern int button_long_flag[MAX_BUTTON];

/* Functions */
void inputReadingInit(void);
int isButtonPressed(int index);
int isButtonLongPressed(int index);
void getKeyInput(void);

#endif /* INC_BUTTON_H_ */
