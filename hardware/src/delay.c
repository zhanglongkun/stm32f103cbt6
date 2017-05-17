#include "stm32f10x.h"
#include "delay.h"


unsigned char UsCount = 0;
unsigned short MsCount = 0;


void Delay_Init()
{
    SysTick->CTRL &= ~(1 << 2);   //设置成 72/8 = 9 MHz (bit2为0时，是AHB的八分频)
    
	UsCount = 9;				  //微秒级系数
	MsCount = UsCount * 1000;	  //毫秒级系数
}

void DelayUs(unsigned short us)
{

	unsigned int ctrlResult = 0;
	
	us &= 0x00FFFFFF;	//SysTick 是一个 24 位的定时器， 即一次最多可以计数 2^24 个时钟脉冲，这个脉冲计数值被保存到 当前计数值寄存器 STK_VAL
	
	SysTick->LOAD = us * UsCount;	
	SysTick->VAL = 0;
	SysTick->CTRL = 1;										
	
	do
	{
		ctrlResult = SysTick->CTRL;
	} while((ctrlResult & 0x01) && !(ctrlResult & (1 << 16)));
    
	SysTick->CTRL = 0;											
	SysTick->VAL = 0;

}

















