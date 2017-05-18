/**
  ******************************************************************************
  * @FileName:     delay.c
  * @Author:       zlk
  * @Version:      V1.0
  * @Date:         2017-5-17 下午 11:33:04
  * @Description:  This file provides all the delay.c functions. 
  ******************************************************************************
  */


#include "stm32f10x.h"
#include "delay.h"


unsigned char UsCount = 0;
unsigned short MsCount = 0;


/**
  ******************************************************************************
  * Function:     Delay_Init()
  * Description:  初始化 Systick Timer
  * Parameters:   viod
  * Returns:      viod
  * Others:       add by zlk, 2017-05-17
  ******************************************************************************
  */ 
void Delay_Init(void)
{
    SysTick->CTRL &= ~(1 << 2);   //设置成 72/8 = 9 MHz (bit2为0时，是AHB的八分频)

    UsCount = 9;				  //微秒级系数
    MsCount = UsCount * 1000;	  //毫秒级系数

    return;
}


/**
  ******************************************************************************
  * Function:     DelayUs()
  * Description:  微秒级延时
  * Parameters:   us--延迟的微秒数
  * Returns:      viod
  * Others:       add by zlk, 2017-05-17
  ******************************************************************************
  */ 
void DelayUs(unsigned short us)
{
    unsigned int ctrlResult = 0;

    us &= 0x00FFFFFF;	//SysTick 是一个 24 位的定时器， 即一次最多可以计数 2^24 个时钟脉冲，这个脉冲计数值被保存到 当前计数值寄存器 STK_VAL

    SysTick->LOAD = us * UsCount;	//当 VAL 为 0 时，由硬件自动把 LOAD 的数据加载到 VAL 中 
    SysTick->VAL = 0;
    SysTick->CTRL = 1;		// bit0 使能位						

    do
    {
        ctrlResult = SysTick->CTRL;
    } while((ctrlResult & 0x01) && !(ctrlResult & (1 << 16)));  // VAL 计数至 0 时，bit16 被置成 1

    SysTick->CTRL = 0;											
    SysTick->VAL = 0;

    return;
}


/**
  ******************************************************************************
  * Function:     DelayMs()
  * Description:  毫秒级延时
  * Parameters:   ms --延迟的毫秒数
  * Returns:      viod
  * Others:       add by zlk, 2017-05-17
  ******************************************************************************
  */ 
void DelayMs(unsigned short ms)
{
    unsigned int ctrlResult = 0;

    ms &= 0x00FFFFFF;	//SysTick 是一个 24 位的定时器， 即一次最多可以计数 2^24 个时钟脉冲，这个脉冲计数值被保存到 当前计数值寄存器 STK_VAL

    SysTick->LOAD = ms * UsCount;	//当 VAL 为 0 时，由硬件自动把 LOAD 的数据加载到 VAL 中 
    SysTick->VAL = 0;
    SysTick->CTRL = 1;		// bit0 使能位						

    do
    {
        ctrlResult = SysTick->CTRL;
    } while((ctrlResult & 0x01) && !(ctrlResult & (1 << 16)));  // VAL 计数至 0 时，bit16 被置成 1

    SysTick->CTRL = 0;											
    SysTick->VAL = 0;

    return;
}
















