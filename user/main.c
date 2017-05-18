
#include "stm32f10x.h"
#include "delay.h"
#include "led.h"



void Hardware_Init(void)
{
    Delay_Init();
	Led_Init();

    return;
}


int main(void)
{
	Hardware_Init();
    Led_Set(LED2, LED_ON);
    DelayMs(2000);
    Led_Set(LED3, LED_ON);
    DelayMs(2000);
    Led_Set(LED4, LED_ON);
    DelayMs(2000);
    Led_Set(LED5, LED_ON);
    DelayMs(2000);

    return 0;
}
