/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SMKCODEACADEMY.h"
#include "ELECTRICAL_module.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
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
osThreadId IdleHandle;
osThreadId ModelHandle;
osThreadId FsmHandle;
osTimerId TimerFSMHandle;
osTimerId TimerMODELHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Idle_task(void const * argument);
void Model_task(void const * argument);
void Fsm_task(void const * argument);
void TimerFSM_callback(void const * argument);
void TimerMODEL_callback(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* GetTimerTaskMemory prototype (linked to static allocation support) */
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/* USER CODE BEGIN GET_TIMER_TASK_MEMORY */
static StaticTask_t xTimerTaskTCBBuffer;
static StackType_t xTimerStack[configTIMER_TASK_STACK_DEPTH];

void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize )
{
  *ppxTimerTaskTCBBuffer = &xTimerTaskTCBBuffer;
  *ppxTimerTaskStackBuffer = &xTimerStack[0];
  *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
  /* place for user code */
}
/* USER CODE END GET_TIMER_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* definition and creation of TimerFSM */
  osTimerDef(TimerFSM, TimerFSM_callback);
  TimerFSMHandle = osTimerCreate(osTimer(TimerFSM), osTimerPeriodic, NULL);

  /* definition and creation of TimerMODEL */
  osTimerDef(TimerMODEL, TimerMODEL_callback);
  TimerMODELHandle = osTimerCreate(osTimer(TimerMODEL), osTimerPeriodic, NULL);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of Idle */
  osThreadDef(Idle, Idle_task, osPriorityIdle, 0, 512);
  IdleHandle = osThreadCreate(osThread(Idle), NULL);

  /* definition and creation of Model */
  osThreadDef(Model, Model_task, osPriorityIdle, 0, 256);
  ModelHandle = osThreadCreate(osThread(Model), NULL);

  /* definition and creation of Fsm */
  osThreadDef(Fsm, Fsm_task, osPriorityIdle, 0, 256);
  FsmHandle = osThreadCreate(osThread(Fsm), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_Idle_task */
/**
  * @brief  Function implementing the Idle thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Idle_task */
void Idle_task(void const * argument)
{
  /* USER CODE BEGIN Idle_task */
	Simulink_Init();
	osTimerStart(TimerFSMHandle, 50); // @20 Hz
	osTimerStart(TimerMODELHandle, 5); // @200 Hz
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);
		osDelay(250);
  }
  /* USER CODE END Idle_task */
}

/* USER CODE BEGIN Header_Model_task */
/**
* @brief Function implementing the Model thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Model_task */
void Model_task(void const * argument)
{
  /* USER CODE BEGIN Model_task */
  /* Infinite loop */
  for(;;)
  {
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		switch_state_set();
		ModelInputUnpack_Simulink();
		Model_Simulink();
		ModelOutputPack_Simulink();
  }
  /* USER CODE END Model_task */
}

/* USER CODE BEGIN Header_Fsm_task */
/**
* @brief Function implementing the Fsm thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Fsm_task */
void Fsm_task(void const * argument)
{
  /* USER CODE BEGIN Fsm_task */
  /* Infinite loop */
  for(;;)
  {
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    FSM_Simulink();
  }
  /* USER CODE END Fsm_task */
}

/* TimerFSM_callback function */
void TimerFSM_callback(void const * argument)
{
  /* USER CODE BEGIN TimerFSM_callback */
	xTaskNotifyGive(FsmHandle);
  /* USER CODE END TimerFSM_callback */
}

/* TimerMODEL_callback function */
void TimerMODEL_callback(void const * argument)
{
  /* USER CODE BEGIN TimerMODEL_callback */
	xTaskNotifyGive(ModelHandle);
  /* USER CODE END TimerMODEL_callback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

