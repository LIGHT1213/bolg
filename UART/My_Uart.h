#ifndef _MY_UART
#define _MY_UART
#include "stm32h7xx_hal.h"
#include "usart.h"
#include "stdio.h"
#include "stdint.h"
#include "dma.h"
#include "stm32h7xx_hal_dma.h"
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif 
void UsartReceive_IDLE(UART_HandleTypeDef *huart);
#define RX_LEN 1024  

typedef struct  
{  
uint8_t  RX_flag:1;        //IDLE receive flag
uint16_t RX_Size;          //receive length
uint8_t  RX_pData[RX_LEN] ; //DMA receive buffer
}USART_RECEIVETYPE;  
extern USART_RECEIVETYPE UsartType;
   

#endif