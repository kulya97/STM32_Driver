//
// Created by huang on 2023-02-11.
//

#ifndef STM32F101_LCD_ST7735_H
#define STM32F101_LCD_ST7735_H

#include "stm32f1xx_hal.h"
#include <stdint.h>
//用户配置

/********************* ST7735S内部实现 ***********************/
#define Lcd_Width 128
#define Lcd_Height 128
#define Pixel_Cnt Lcd_Width*Lcd_Height
/**************************************/
#define Delay(ms) HAL_Delay(ms)

#define     ST7735S_RD_H      GPIOC->BSRR=1<<6
#define     ST7735S_RS_H      GPIOC->BSRR=1<<8
#define     ST7735S_WR_H      GPIOC->BSRR=1<<7
#define     ST7735S_RST_H     GPIOA->BSRR=1
#define     ST7735S_CS_H      GPIOC->BSRR=1<<9


#define     ST7735S_RD_L      GPIOC->BRR=1<<6
#define     ST7735S_RS_L      GPIOC->BRR=1<<8
#define     ST7735S_WR_L      GPIOC->BRR=1<<7
#define     ST7735S_RST_L     GPIOA->BRR=1
#define     ST7735S_CS_L      GPIOC->BRR=1<<9

#define ST7735S_WRITE(Color)  GPIOB->ODR=Color;

/**************************************/
void ST7735S_WriteCmd(uint8_t CMD);

void ST7735S_WriteData(uint8_t DATA);

void ST7735S_WriteColor(uint16_t Color);

void ST7735S_SetAddress(uint8_t site_x, uint8_t site_y, uint8_t size_x, uint8_t size_y);

/**************************************/
void LCD_init(void);

void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t Color);

void LCD_Clear(uint16_t Color);

#endif //STM32F101_LCD_ST7735_H
