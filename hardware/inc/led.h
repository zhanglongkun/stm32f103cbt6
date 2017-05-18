/**
  ******************************************************************************
  * @@FileName£º   led.h 
  * @author£º      zlk
  * @version£º     V1.0
  * @Date:         2017-5-17 ÏÂÎç 11:48:52
  * @Description   This file contains all the functions prototypes for the BOARD 
  ******************************************************************************
  */ 


#ifndef __LED_H
#define __LED_H

#define LED2 GPIO_Pin_6
#define LED3 GPIO_Pin_7
#define LED4 GPIO_Pin_8
#define LED5 GPIO_Pin_9


typedef enum
{
	LED_OFF = 0,
	LED_ON

} LED_ENUM;


void Led_Init(void);

void Led_Set(uint16_t GPIO_Pin, LED_ENUM status);


#endif  /* __LED_H */


