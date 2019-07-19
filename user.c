#include "main.h"
#include "cmsis_os.h"

/* External Data */
extern UART_HandleTypeDef huart1;
extern osThreadId myTask02Handle;
extern osMessageQId myQueue01Handle;

/* Callback Function */
uint8_t g_RxData;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Save Rx Data */
  uint8_t rxData = g_RxData;
  /* Re-Initialize Rx */
  HAL_UART_Receive_IT(&huart1, &g_RxData, 1);
  /* Put Message */
  osMessagePut(myQueue01Handle, (uint32_t)rxData, 0);
}

void StartTask02(void const * argument)
{
  /* Initlize Rx */
  HAL_UART_Receive_IT(&huart1, &g_RxData, 1);

  /* Infinite loop */
  for(;;)
  {
    /* Get Message */
    osEvent evt = osMessageGet(myQueue01Handle, osWaitForever);
    /* Echo Back */
    uint8_t rxData = (uint8_t)(evt.value.v);
    HAL_UART_Transmit_IT(&huart1, &rxData, 1);
    osDelay(1);
  }
}

