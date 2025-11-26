/*
 * scheduler.c
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

/* Includes */
#include "scheduler.h"

/* Variables */
sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t currentIndexTask = 0;
uint8_t Error_code_G = 0;

/* Functions */

/**
 * @brief	Initialize the scheduler
 * @param	None
 * @retval	None
 */
void SCH_Init(void) {
	for (uint8_t idx = 0; idx < SCH_MAX_TASKS; idx++) {
		SCH_tasks_G[idx].pTask = 0;
		SCH_tasks_G[idx].Delay = 0;
		SCH_tasks_G[idx].Period = 0;
		SCH_tasks_G[idx].RunMe = 0;
	}
}

/**
 * @brief	Causes a task (function) to be executed at regular intervals or
 * 			after a user-defined delay
 * @param	*pFunction() : pointer to the task that need to be executed
 * 			DELAY : Delay (ticks) until the task will be run next
 * 			PERIOD : Interval (ticks) between subsequent runs
 * @retval	None
 */
void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
	uint8_t index = 0;
	// Find a gap in the task array (if there is one)
	while ((SCH_tasks_G[index].pTask != 0) && (index < SCH_MAX_TASKS)) {
		index++;
	}

	// If there is no space available in the task array (Task list is full)
	if (index == SCH_MAX_TASKS) {
		// Error_code_G = ERROR_SCH_TOO_MANY_TASKS;	// Set the global error variable
		return;										// return an error code
	}

	// If there is a space in the task array
	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = DELAY;
	SCH_tasks_G[index].Period = PERIOD;
	SCH_tasks_G[index].RunMe = 0;
	// Return the position of the task (for deletion later)
	// return index
}

/**
 * @brief	Update the properties of tasks (DELAY and PERIOD) - just update, not run tasks
 * @param	None
 * @retval	None
 */
void SCH_Update(void) {
	// NOTE: calculations are in TICKS (not mili-seconds)
	for (uint8_t index = 0; index < SCH_MAX_TASKS; index++) {
		// Check if there is a task at this location
		if (SCH_tasks_G[index].pTask) {
			if (SCH_tasks_G[index].Delay == 0) {
				// The task is due to run
				SCH_tasks_G[index].RunMe += 1; 		// Increase the 'RunMe' flag
				if (SCH_tasks_G[index].Period) {
					// Schedule periodic tasks to run again
					SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
				}
			} else {
				// Not yet ready to run; just decrease the delay
				SCH_tasks_G[index].Delay -= 1;
			}
		}
	}
}

/**
 * @brief	Dispatch tasks that are due to run
 * @param	None
 * @retval	None
 */
void SCH_Dispatch_Tasks(void) {
	// Dispatches (run) the next task (if one is ready)
	for (uint8_t index = 0; index < SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].RunMe > 0) {
			(*SCH_tasks_G[index].pTask)();		// Run the task
			SCH_tasks_G[index].RunMe -= 1;		// Reset by reduce the 'RunMe' flag
			// Periodic tasks will automatically run again
			// - if this is a 'one-shot' task, remove it from the array
			if (SCH_tasks_G[index].Period == 0) {
				SCH_Delete_Task(index);
			}
		}
	}
	// Report system status
	// SCH_Report_Status();
}

/**
 * @brief	Remove the task from the task list
 * @param	taskIndex : the position of the task that need to be removed
 * @retval	None
 */
void SCH_Delete_Task(uint32_t taskID) {
	if (SCH_tasks_G[taskIndex].pTask == 0) {
		// No task at this location
		// Set the global error variable
		// Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		// Return an error code
		// Return_code = RETURN_ERROR;
		return;
	} else {
		// Return_code = RETURN_NORMAL;
		return;
	}
	SCH_tasks_G[taskIndex].pTask = 0x0000;
	SCH_tasks_G[taskIndex].Delay = 0;
	SCH_tasks_G[taskIndex].Period = 0;
	SCH_tasks_G[taskIndex].RunMe = 0;
	// return Return_code; 		// return status
}
