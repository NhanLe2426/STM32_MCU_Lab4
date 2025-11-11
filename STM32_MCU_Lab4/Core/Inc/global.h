/*
 * global.h
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

/* Includes */
#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "traffic_light.h"
#include "led_7seg.h"

/* Define */

// STATES OF AUTOMATIC MODE
#define INIT_AUTO	1
#define RED_GREEN	2
#define RED_YELLOW	3
#define GREEN_RED	4
#define YELLOW_RED	5
// ---------------------------------

// STATES OF MANUAL MODE
#define RED_GREEN_MAN	7		// Way 1 (Vertical) is RED, Way 2 (Horizontal) is GREEN
#define GREEN_RED_MAN	8		// Way 1 (Vertical) is GREEN, Way 2 (Horizontal) is RED
#define INIT_MAN		9
// ---------------------------------

// STATES OF CONFIG MODE
#define RED_CONFIG		10
#define YELLOW_CONFIG	11
#define GREEN_CONFIG	12
#define INIT_CONFIG		13
// ---------------------------------

/* Variables */
extern int status;				// The status of FSM
extern int redDuration;
extern int yellowDuration;
extern int greenDuration;
extern int index_led;

#endif /* INC_GLOBAL_H_ */
