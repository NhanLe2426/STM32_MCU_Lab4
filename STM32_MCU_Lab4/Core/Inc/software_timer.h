/*
 * software_timer.h
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

/* Includes */
#include "main.h"

/* Define */
#define TIMER_CYCLE		10

// Number of Software Timers
#define MAX_TIMER		10

/* Variables */
extern int timer_flag[MAX_TIMER];
extern int timer_counter[MAX_TIMER];

/* Functions */
void setTimer(int index, int duration);
int isTimerExpired(int index);
void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
