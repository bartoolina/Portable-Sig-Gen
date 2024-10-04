/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : app_freertos.c
 * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
// #include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
// typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
static StaticTask_t exampleTaskTCB;
static StackType_t exampleTaskStack[configMINIMAL_STACK_SIZE];
// osThreadId_t defaultTaskHandle;
// uint32_t defaultTaskBuffer[128];
// osStaticThreadDef_t defaultTaskControlBlock;
// const osThreadAttr_t defaultTask_attributes = {
// 	.name = "defaultTask",
// 	.stack_mem = &defaultTaskBuffer[0],
// 	.stack_size = sizeof(defaultTaskBuffer),
// 	.cb_mem = &defaultTaskControlBlock,
// 	.cb_size = sizeof(defaultTaskControlBlock),
// 	.priority = (osPriority_t)osPriorityNormal,
// };

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

static void exampleTask(void *parameters);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void)
{
	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* creation of defaultTask */
	// defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);
	(void)xTaskCreateStatic(exampleTask,
							"example",
							configMINIMAL_STACK_SIZE,
							NULL,
							configMAX_PRIORITIES - 1U,
							&(exampleTaskStack[0]),
							&(exampleTaskTCB));
	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	/* USER CODE END RTOS_THREADS */

	/* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
	/* USER CODE END RTOS_EVENTS */
}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
static void exampleTask(void *parameters)
{
	UNUSED(parameters);
	/* USER CODE BEGIN StartDefaultTask */
	/* Infinite loop */
	for (;;)
	{
		vTaskDelay(100);
	}
	/* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
