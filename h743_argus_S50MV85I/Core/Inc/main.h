/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

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
#define TIM5_BUS_CLK (HAL_RCC_GetPCLK1Freq() << 1)
#define TIM6_BUS_CLK (HAL_RCC_GetPCLK1Freq() << 1)
#define S50MV85I_SPI_NSS_Pin GPIO_PIN_4
#define S50MV85I_SPI_NSS_GPIO_Port GPIOA
#define S50MV85I_IRQ_Pin GPIO_PIN_15
#define S50MV85I_IRQ_GPIO_Port GPIOB
#define S50MV85I_IRQ_EXTI_IRQn EXTI15_10_IRQn
#define S50MV85I_SPI_SCK_Pin GPIO_PIN_3
#define S50MV85I_SPI_SCK_GPIO_Port GPIOB
#define S50MV85I_SPI_MISO_Pin GPIO_PIN_4
#define S50MV85I_SPI_MISO_GPIO_Port GPIOB
#define S50MV85I_SPI_MOSI_Pin GPIO_PIN_5
#define S50MV85I_SPI_MOSI_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
