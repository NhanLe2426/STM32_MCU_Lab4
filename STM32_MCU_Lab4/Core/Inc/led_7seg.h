/*
 * led_7seg.h
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

#ifndef INC_LED_7SEG_H_
#define INC_LED_7SEG_H_

/* Includes */
#include "main.h"

/* Variables */
extern int led_buffer[4];

/* Functions */
void display7SEG(int num);
void clear7SEG(void);
void update7SEG(int index);
void updateLedBuffer(int index, int value);

#endif /* INC_LED_7SEG_H_ */
