/*
 * software_timer.c
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

/* Includes */
#include "software_timer.h"

/* Variables */
int timer_flag[MAX_TIMER] = { 0 };
int timer_counter[MAX_TIMER] = { 0 };

/* Functions */

/**
 * @brief	Set duration of software timer interrupt at the index position
 * @param	index : The index of current timer
 * 			duration : Duration of software timer interrupt
 * @retval 	None
 */
void setTimer(int index, int duration) {
	timer_counter[index] = duration / TIMER_CYCLE;
	timer_flag[index] = 0;
}

/**
 * @brief	Check if the index timer is expired or not
 * @param	index : The index of current timer
 * @retval	1 if the timer is expired (flag = 1) or 0 if it is not (flag = 0)
 */
int isTimerExpired(int index) {
	if (timer_flag[index] == 1) {
		return 1;
	}
	return 0;
}

/**
 * @brief	Run the timer
 * @param	None
 * @retval	None
 */
void timerRun(void) {
	for (int i = 0; i < MAX_TIMER; i++) {
		if (timer_counter[i] > 0) {
			timer_counter[i]--;
			if (timer_counter[i] <= 0) {
				timer_flag[i] = 1;
			}
		}
	}
}
