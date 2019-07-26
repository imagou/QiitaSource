#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "cmsis_os.h"

/* Definitions */
#define COMMAND_LEN (16)
uint32_t g_ToggleMsec = 500;

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
  uint8_t rxBuffer[COMMAND_LEN * 2];
  int32_t rxCount = 0;

  /* Initlize Rx */
  HAL_UART_Receive_IT(&huart1, &g_RxData, 1);

  /* Infinite loop */
  for(;;)
  {
    /* Get Message */
    osEvent evt = osMessageGet(myQueue01Handle, osWaitForever);

    /* Receive & Parse Data */
    uint8_t rxData = (uint8_t)(evt.value.v);
    switch (rxData) {
    /* Delimiter */
    case 0x0A:
      /* To Command Parser */
      break;
    /* Buffering */
    default:
      if (isprint(rxData)) {
        if (rxCount < COMMAND_LEN) {
          rxBuffer[rxCount++] = tolower(rxData);
        }
      }
      continue;
    }

    /* Command Parser */
    rxBuffer[rxCount] = 0x00;
    if (!strcmp((const char *)rxBuffer, "hello")) {
      const char *ptr = "world\r\n";
      HAL_UART_Transmit_IT(&huart1, (uint8_t *)ptr, strlen(ptr));
    }
    else {
        int32_t num = atoi((const char *)rxBuffer);
        /* Update Toggle Timing */
        if (0 < num) g_ToggleMsec = num;
    }
    rxCount = 0;
  }
}

void StartTask03(void const * argument)
{
  for(;;)
  {
    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
    osDelay(g_ToggleMsec);
  }
}
