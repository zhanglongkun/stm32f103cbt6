/**
  ******************************************************************************
  * @FileName:     delay.c
  * @Author:       zlk
  * @Version:      V1.0
  * @Date:         2017-5-17 ���� 11:33:04
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
  * Description:  ��ʼ�� Systick Timer
  * Parameters:   viod
  * Returns:      viod
  * Others:       add by zlk, 2017-05-17
  ******************************************************************************
  */ 
void Delay_Init(void)
{
    SysTick->CTRL &= ~(1 << 2);   //���ó� 72/8 = 9 MHz (bit2Ϊ0ʱ����AHB�İ˷�Ƶ)

    UsCount = 9;				  //΢�뼶ϵ��
    MsCount = UsCount * 1000;	  //���뼶ϵ��

    return;
}


/**
  ******************************************************************************
  * Function:     DelayUs()
  * Description:  ΢�뼶��ʱ
  * Parameters:   us--�ӳٵ�΢����
  * Returns:      viod
  * Others:       add by zlk, 2017-05-17
  ******************************************************************************
  */ 
void DelayUs(unsigned short us)
{
    unsigned int ctrlResult = 0;

    us &= 0x00FFFFFF;	//SysTick ��һ�� 24 λ�Ķ�ʱ���� ��һ�������Լ��� 2^24 ��ʱ�����壬����������ֵ�����浽 ��ǰ����ֵ�Ĵ��� STK_VAL

    SysTick->LOAD = us * UsCount;	//�� VAL Ϊ 0 ʱ����Ӳ���Զ��� LOAD �����ݼ��ص� VAL �� 
    SysTick->VAL = 0;
    SysTick->CTRL = 1;		// bit0 ʹ��λ						

    do
    {
        ctrlResult = SysTick->CTRL;
    } while((ctrlResult & 0x01) && !(ctrlResult & (1 << 16)));  // VAL ������ 0 ʱ��bit16 ���ó� 1

    SysTick->CTRL = 0;											
    SysTick->VAL = 0;

    return;
}


/**
  ******************************************************************************
  * Function:     DelayMs()
  * Description:  ���뼶��ʱ
  * Parameters:   ms --�ӳٵĺ�����
  * Returns:      viod
  * Others:       add by zlk, 2017-05-17
  ******************************************************************************
  */ 
void DelayMs(unsigned short ms)
{
    unsigned int ctrlResult = 0;

    ms &= 0x00FFFFFF;	//SysTick ��һ�� 24 λ�Ķ�ʱ���� ��һ�������Լ��� 2^24 ��ʱ�����壬����������ֵ�����浽 ��ǰ����ֵ�Ĵ��� STK_VAL

    SysTick->LOAD = ms * UsCount;	//�� VAL Ϊ 0 ʱ����Ӳ���Զ��� LOAD �����ݼ��ص� VAL �� 
    SysTick->VAL = 0;
    SysTick->CTRL = 1;		// bit0 ʹ��λ						

    do
    {
        ctrlResult = SysTick->CTRL;
    } while((ctrlResult & 0x01) && !(ctrlResult & (1 << 16)));  // VAL ������ 0 ʱ��bit16 ���ó� 1

    SysTick->CTRL = 0;											
    SysTick->VAL = 0;

    return;
}
















