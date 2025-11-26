/*
 * scheduler.h
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

/* Includes */
#include "stdint.h"

/* Typedef */
typedef struct {
	void (*pTask)(void);		// Pointer to the task (must be a 'void (void)' function
	uint32_t	Delay;			// Delay (ticks) until the function will (next) be run
	uint32_t	Period;			// Interval (ticks) between subsequent runs
	uint8_t		RunMe;			// Incremented (by scheduler) when task is due to execute

	uint32_t	TaskID;
} sTasks;

/* Define */
#define SCH_MAX_TASKS	40
#define NO_TASK_ID		0
#define TICKS			10

/* Variables */

/* Functions */
void SCH_Init(void);
void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */
