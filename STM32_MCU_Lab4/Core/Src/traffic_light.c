/*
 * traffic_light.c
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

/* Includes */
#include "traffic_light.h"

/* Variables */


/* Functions */

/**
 * @brief	Control the traffic light on way 1 (vertical)
 * @param	red, yellow, green : The status of 3 LEDs: red, yellow and green
 * @retval	None
 */
void setLightWay1(int red, int yellow, int green) {
	HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, red);
	HAL_GPIO_WritePin(YEL_LED_1_GPIO_Port, YEL_LED_1_Pin, yellow);
	HAL_GPIO_WritePin(GRN_LED_1_GPIO_Port, GRN_LED_1_Pin, green);
}

/**
 * @brief	Control the traffic light on way 2 (horizontal)
 * @param	red, yellow, green : The status of 3 LEDs: red, yellow and green
 * @retval	None
 */
void setLightWay2(int red, int yellow, int green) {
	HAL_GPIO_WritePin(RED_LED_2_GPIO_Port, RED_LED_2_Pin, red);
	HAL_GPIO_WritePin(YEL_LED_2_GPIO_Port, YEL_LED_2_Pin, yellow);
	HAL_GPIO_WritePin(GRN_LED_2_GPIO_Port, GRN_LED_2_Pin, green);
}

/**
 * @brief	Turn ON and OFF all red LEDs
 * @param	LEDstatus : The state of red LEDs (ON / OFF)
 * @retval	None
 */
void setAllRedLED(int LEDstatus) {
	switch (LEDstatus) {
	case ON:
		HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, RESET);
		HAL_GPIO_WritePin(RED_LED_2_GPIO_Port, RED_LED_2_Pin, RESET);
		break;

	case OFF:
		HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, SET);
		HAL_GPIO_WritePin(RED_LED_2_GPIO_Port, RED_LED_2_Pin, SET);
		break;

	default:
		break;
	}
}

/**
 * @brief	Turn ON and OFF all yellow LEDs
 * @param	LEDstatus : The state of yellow LEDs (ON / OFF)
 * @retval	None
 */
void setAllYellowLED(int LEDstatus) {
	switch (LEDstatus) {
	case ON:
		HAL_GPIO_WritePin(YEL_LED_1_GPIO_Port, YEL_LED_1_Pin, RESET);
		HAL_GPIO_WritePin(YEL_LED_2_GPIO_Port, YEL_LED_2_Pin, RESET);
		break;

	case OFF:
		HAL_GPIO_WritePin(YEL_LED_1_GPIO_Port, YEL_LED_1_Pin, SET);
		HAL_GPIO_WritePin(YEL_LED_2_GPIO_Port, YEL_LED_2_Pin, SET);
		break;

	default:
		break;
	}
}

/**
 * @brief	Turn ON and OFF all green LEDs
 * @param	LEDstatus : The state of green LEDs (ON / OFF)
 * @retval	None
 */
void setAllGreenLED(int LEDstatus) {
	switch (LEDstatus) {
	case ON:
		HAL_GPIO_WritePin(GRN_LED_1_GPIO_Port, GRN_LED_1_Pin, RESET);
		HAL_GPIO_WritePin(GRN_LED_2_GPIO_Port, GRN_LED_2_Pin, RESET);
		break;

	case OFF:
		HAL_GPIO_WritePin(GRN_LED_1_GPIO_Port, GRN_LED_1_Pin, SET);
		HAL_GPIO_WritePin(GRN_LED_2_GPIO_Port, GRN_LED_2_Pin, SET);
		break;

	default:
		break;
	}
}
