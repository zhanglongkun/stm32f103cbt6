#include "stm32f10x.h"
#include "delay.h"


unsigned char UsCount = 0;
unsigned short MsCount = 0;


void Delay_Init()
{
    SysTick->CTRL &= ~(1 << 2);   //���ó� 72/8 = 9 MHz (bit2Ϊ0ʱ����AHB�İ˷�Ƶ)
    
	UsCount = 9;				  //΢�뼶ϵ��
	MsCount = UsCount * 1000;	  //���뼶ϵ��
}

void DelayUs(unsigned short us)
{

	unsigned int ctrlResult = 0;
	
	us &= 0x00FFFFFF;	//SysTick ��һ�� 24 λ�Ķ�ʱ���� ��һ�������Լ��� 2^24 ��ʱ�����壬����������ֵ�����浽 ��ǰ����ֵ�Ĵ��� STK_VAL
	
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

















