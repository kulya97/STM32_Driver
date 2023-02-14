//
// Created by huang on 2022-10-07.
//
#ifndef STM32F101_LCD_SSD1289_H
#define STM32F101_LCD_SSD1289_H

#include "stm32f1xx_hal.h"
#include <stdint.h>
#include <stdio.h>
/**************控制io定义************************/
#define LCD_RD_Pin GPIO_PIN_6
#define LCD_WR_Pin GPIO_PIN_7
#define LCD_RS_Pin GPIO_PIN_8
#define LCD_CS_Pin GPIO_PIN_9
/**************************************/
#define Delay(ms) HAL_Delay(ms)
#define SSD1289_WRITE(x) GPIOB->ODR=x;
#define SSD1289_CS_HI  GPIOC->BSRR=1<<9    //     PC9
#define SSD1289_DATA  GPIOC->BSRR=1<<8     //     PC8
#define SSD1289_WR_HI  GPIOC->BSRR=1<<7    //      PC7
#define SSD1289_RD_HI  GPIOC->BSRR=1<<6    //      PC6

#define SSD1289_CS_LO  GPIOC->BRR=1<<9     //     PC9
#define SSD1289_CMD  GPIOC->BRR=1<<8       //    PC8
#define SSD1289_WR_LO  GPIOC->BRR=1<<7     //        PC7
#define SSD1289_RD_LO  GPIOC->BRR=1<<6     //       PC6


/**************************************/
#define HORIZONTAL 1
#if HORIZONTAL
#define Lcd_Width 320
#define Lcd_Height 240
#else
#define Lcd_Width 240
#define Lcd_Height 320
#endif
#define Pixel_Cnt Lcd_Width*Lcd_Height
/**************************************/
#define Black   0x0000
#define Red     0xF800
#define Green   0x07E0
#define Blue    0x001F
#define White   0xFFFF
#define Purple  0xF11F
#define Yellow  0xFFE0
#define Cyan    0x07FF

/*****************base*********************/
void SSD1289_WriteCmd(uint16_t CMD);

void SSD1289_WriteData(uint16_t DATA);

void SSD1289_WriteCmdData(uint16_t CMD, uint16_t DATA);

void SSD1289_WriteColor(uint16_t Color);

void SSD1289_SetAddress(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

/**************************************/
void LCD_init(void);

void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t Color);

void LCD_Clear(uint16_t color);
/**************************************/
#endif //STM32F101_LCD_SSD1289_H
