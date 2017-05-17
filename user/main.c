
#include "stm32f10x.h"
#include "delay.h"
#include "led.h"



void Hardware_Init(void)
{
    Delay_Init();
	Led_Init();

}


int main(void)
{
	Hardware_Init();
   // DelayMs(2);
    //Led3_Set(LED_OFF);
}
