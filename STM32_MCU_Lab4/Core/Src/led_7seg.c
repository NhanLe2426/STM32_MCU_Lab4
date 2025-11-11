/*
 * led_7seg.c
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

/* Includes */
#include "led_7seg.h"

/* Variables */
int led_buffer[4] = { 0 };

/* Functions */

/**
 * @brief	Display number on 7-segment LED
 * @param	num : The number displayed on LED
 * @retval	None
 */
void display7SEG(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);

		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, SET);
		break;

	case 1:
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);

		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, SET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, SET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, SET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, SET);
		break;

	case 2:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, SET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, SET);
		break;

	case 3:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, SET);
		break;

	case 4:
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, SET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, SET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		break;

	case 5:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, SET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		break;

	case 6:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, SET);
		break;

	case 7:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);

		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, SET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, SET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, SET);
		break;

	case 8:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);
		break;

	case 9:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		break;

	default:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, SET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, SET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, SET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, SET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, SET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, SET);
		break;
	}
}

/**
 * @brief	Clear number on 7-segment LED
 * @param	None
 * @retval	None
 */
void clear7SEG(void) {
	HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, SET);
	HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, SET);
	HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, SET);
	HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, SET);
	HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
	HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, SET);
	HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, SET);
}

/**
 * @brief	Update the 7-segment LEDs based on an array of 4 integer numbers
 * @param	index : The index of LED displayed
 * @retval	None
 */
void update7SEG(int index) {
	switch(index) {
	case 0:
		// Display the first 7SEG with led_buffer[0]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

		display7SEG(led_buffer[0]);
		break;

	case 1:
		// Display the second 7SEG with led_buffer[1]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

		display7SEG(led_buffer[1]);
		break;

	case 2:
		// Display the third 7SEG with led_buffer[2]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

		display7SEG(led_buffer[2]);
		break;

	case 3:
		// Display the forth 7SEG with led_buffer[3]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);

		display7SEG(led_buffer[3]);
		break;

	default:
		break;
	}
}

/**
 * @brief	Update the led buffer at the index position with the input value
 * @param	index : The index of led buffer
 *			value : The updated value
 * @retval	None
 */
void updateLedBuffer(int index, int value) {
	if (value <= 0) {
		led_buffer[index] = 0;
	} else {
		led_buffer[index] = value;
	}
}
