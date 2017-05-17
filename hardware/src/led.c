/**
  ******************************************************************************
  * @FileName:     led.c
  * @Author:       zlk
  * @Version:      V1.0
  * @Date:         2017-5-17 下午 11:49:23
  * @Description:  This file provides all the led.c functions. 
  ******************************************************************************
  */


#include "stm32f10x.h"
#include "led.h"


LED_STATUS ledStatus;


/**
  ******************************************************************************
  * Function:     Led_Init()
  * Description:  描述
  * Parameters:   void
  * Returns:      void
  * Others:       add by zlk, 2017-05-17
  ******************************************************************************
  */ 
void Led_Init(void)
{
    GPIO_InitTypeDef gpioInit;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);   //打开 GPIOB 时钟

    gpioInit.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_6;
    gpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
    gpioInit.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOB, &gpioInit);
    Led3_Set(LED_OFF);
}

void Led3_Set(LED_ENUM status)
{

    GPIO_WriteBit(GPIOB, GPIO_Pin_7, status != LED_ON ? Bit_SET : Bit_RESET);
    ledStatus.Led3Sta = status;
}



