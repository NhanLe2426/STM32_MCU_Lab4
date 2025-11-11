/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED_LED_1_Pin GPIO_PIN_0
#define RED_LED_1_GPIO_Port GPIOA
#define YEL_LED_1_Pin GPIO_PIN_1
#define YEL_LED_1_GPIO_Port GPIOA
#define GRN_LED_1_Pin GPIO_PIN_2
#define GRN_LED_1_GPIO_Port GPIOA
#define RED_LED_2_Pin GPIO_PIN_3
#define RED_LED_2_GPIO_Port GPIOA
#define YEL_LED_2_Pin GPIO_PIN_4
#define YEL_LED_2_GPIO_Port GPIOA
#define GRN_LED_2_Pin GPIO_PIN_5
#define GRN_LED_2_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_7
#define LED_GPIO_Port GPIOA
#define LED7_a_Pin GPIO_PIN_0
#define LED7_a_GPIO_Port GPIOB
#define LED7_b_Pin GPIO_PIN_1
#define LED7_b_GPIO_Port GPIOB
#define LED7_c_Pin GPIO_PIN_2
#define LED7_c_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_8
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_9
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_10
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_11
#define EN3_GPIO_Port GPIOA
#define LED7_d_Pin GPIO_PIN_3
#define LED7_d_GPIO_Port GPIOB
#define LED7_e_Pin GPIO_PIN_4
#define LED7_e_GPIO_Port GPIOB
#define LED7_f_Pin GPIO_PIN_5
#define LED7_f_GPIO_Port GPIOB
#define LED7_g_Pin GPIO_PIN_6
#define LED7_g_GPIO_Port GPIOB
#define BUTTON_1_Pin GPIO_PIN_7
#define BUTTON_1_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_8
#define BUTTON_2_GPIO_Port GPIOB
#define BUTTON_3_Pin GPIO_PIN_9
#define BUTTON_3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
