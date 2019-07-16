#include "main.h"
#include "cmsis_os.h"

/* External Data */
extern UART_HandleTypeDef huart1;
extern osThreadId myTask02Handle;

/* Message Queue Definition(s) */
osMessageQDef(g_MsgQId, 16, uint8_t);
osMessageQId g_MsgQId;

/* Callback Function */
uint8_t g_RxData;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Save Rx Data */
  uint8_t rxData = g_RxData;
  /* Re-Initialize Rx */
  HAL_UART_Receive_IT(&huart1, &g_RxData, 1);
  /* Put Message */
  osMessagePut(g_MsgQId, (uint32_t)rxData, 0);
}

void StartTask02(void const * argument)
{
  /* Initlize Rx */
  HAL_UART_Receive_IT(&huart1, &g_RxData, 1);
  /* Create Message Queue */
  g_MsgQId = osMessageCreate(osMessageQ(g_MsgQId), NULL);

  /* Infinite loop */
  for(;;)
  {
    /* Get Message */
    osEvent evt = osMessageGet(g_MsgQId, osWaitForever);
    /* Echo Back */
    uint8_t rxData = (uint8_t)(evt.value.v);
    HAL_UART_Transmit_IT(&huart1, &rxData, 1);
    osDelay(1);
  }
}

