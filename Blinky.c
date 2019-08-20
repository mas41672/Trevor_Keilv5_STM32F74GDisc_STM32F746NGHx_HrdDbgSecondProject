/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher for STM32F746G-Discovery
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2004-2015 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/


#include "Board_LED.h"
#include "stm32f7xx_hal.h"
#include "RTE_Components.h"

extern void MPU_Config(void);
extern void SystemClock_Config (void);

int ticks = 0;

void SysTick_Handler (void)
{
	ticks++	;
	
}

void delay(uint32_t period)
{
	while(ticks < period)
	{
		;
	}
	ticks = 0;
}
/**
  * Main function
  */
int main (void) {

//  MPU_Config();                             /* Configure the MPU              */
  HAL_Init();                               /* Initialize the HAL Library     */
  SystemClock_Config();                     /* Configure the System Clock     */
  LED_Initialize();                         /* LED Initialization             */

  while (1) {
	delay(100);
	LED_On(0);
	delay(100);
	LED_Off(0);
	
  }
}
