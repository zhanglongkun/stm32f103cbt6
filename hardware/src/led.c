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


/**
  ******************************************************************************
  * Function:     Led_Init()
  * Description:  初始化 LED2、LED3、LED4、LED5
  * Parameters:   void
  * Returns:      void
  * Others:       add by zlk, 2017-05-17
  ******************************************************************************
  */ 
void Led_Init(void)
{
    GPIO_InitTypeDef gpioInit;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);   //打开 GPIOB 时钟

    gpioInit.GPIO_Pin = LED2 | LED3| LED4 | LED5;
    gpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
    gpioInit.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOB, &gpioInit);
    
    Led_Set(LED2, LED_OFF);
    Led_Set(LED3, LED_OFF);
    Led_Set(LED4, LED_OFF);
    Led_Set(LED5, LED_OFF);

    return;
}

void Led_Set(uint16_t GPIO_Pin, LED_ENUM status)
{
    GPIO_WriteBit(GPIOB, GPIO_Pin, status != LED_ON ? Bit_SET : Bit_RESET);

    return;
}



