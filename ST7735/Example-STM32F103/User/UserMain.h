/*
 * UserMain.h
 *
 *  Created on: Jan 11, 2021
 *      Author: huang
 */


#ifndef _USERMAIN_H_
#define _USERMAIN_H_

#include "stm32f1xx_hal.h"
#include "main.h"
#include <stdint.h>
#include <stdio.h>

#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOD

void UserSysInit();

void UserLoop();

void UserConfigInit();

#endif /* _USERMAIN_H_ */
