#include "My_Uart.h"
extern UART_HandleTypeDef huart1;
USART_RECEIVETYPE UsartType __attribute__((section(".ARM.__at_0x24000000")));;
int fputc(int ch,FILE *f)
{
    uint8_t temp[1]={ch};
    HAL_UART_Transmit(&huart1,temp,1,10);
		return ch;
}


PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&huart1,(uint8_t*)&ch,1,10);
	return ch;
}
void UsartReceive_IDLE(UART_HandleTypeDef *huart)
{  
    uint32_t temp;
  
    if((__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE) != RESET)) 
    {   
        __HAL_UART_CLEAR_IDLEFLAG(&huart1);
        HAL_UART_DMAStop(&huart1);
        temp = ((DMA_Stream_TypeDef *)huart1.hdmarx->Instance)->NDTR;			
        UsartType.RX_Size =  RX_LEN - temp;
        HAL_UART_Receive_DMA(&huart1,UsartType.RX_pData,RX_LEN);
				UsartType.RX_flag=1;
    }
}
