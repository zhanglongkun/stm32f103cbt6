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

typedef struct
{

	_Bool Led2Sta;
	_Bool Led3Sta;
	_Bool Led4Sta;
	_Bool Led5Sta;

} LED_STATUS;

extern LED_STATUS ledStatus;

typedef enum
{

	LED_OFF = 0,
	LED_ON

} LED_ENUM;


void Led_Init(void);

void Led2_Set(LED_ENUM status);

void Led3_Set(LED_ENUM status);

void Led4_Set(LED_ENUM status);

void Led5_Set(LED_ENUM status);



#endif  /* __LED_H */


