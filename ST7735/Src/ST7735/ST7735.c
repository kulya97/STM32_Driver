//
// Created by huang on 2023-02-11.
//

#include "ST7735.h"

void ST7735S_WriteData(uint8_t data) {
    ST7735S_RS_H;
    ST7735S_WR_L;
    ST7735S_WRITE(0XFF00 | (data));
    ST7735S_WR_H;
}

void ST7735S_WriteCmd(uint8_t cmd) {
    ST7735S_RS_L;
    ST7735S_WR_L;
    ST7735S_WRITE(0XFF00 | (cmd));
    ST7735S_WR_H;
}

void ST7735S_WriteColor(uint16_t Color) {
    ST7735S_RS_H;
    ST7735S_WR_L;
    ST7735S_WRITE(Color >> 8);
    ST7735S_WR_H;
    ST7735S_WR_L;
    ST7735S_WRITE(Color);
    ST7735S_WR_H;
}

void LCD_init() {
    //初始化总线
    ST7735S_RST_L;
    ST7735S_WR_L;
    ST7735S_RD_H;
    ST7735S_CS_H;
    ST7735S_RS_L;
    Delay(100);
    ST7735S_RST_H;
    ST7735S_CS_L;
    Delay(500);
    ST7735S_WriteCmd(0x11);
    Delay(120);
    ST7735S_WriteCmd(0xB1);
    ST7735S_WriteData(0x01);
    ST7735S_WriteData(0x2C);
    ST7735S_WriteData(0x2D);
    ST7735S_WriteCmd(0xB2);
    ST7735S_WriteData(0x01);
    ST7735S_WriteData(0x2C);
    ST7735S_WriteData(0x2D);
    ST7735S_WriteCmd(0xB3);
    ST7735S_WriteData(0x01);
    ST7735S_WriteData(0x2C);
    ST7735S_WriteData(0x2D);
    ST7735S_WriteData(0x01);
    ST7735S_WriteData(0x2C);
    ST7735S_WriteData(0x2D);
    ST7735S_WriteCmd(0xB4);
    ST7735S_WriteData(0x07);
    ST7735S_WriteCmd(0xC0);
    ST7735S_WriteData(0xA2);
    ST7735S_WriteData(0x02);
    ST7735S_WriteData(0x84);
    ST7735S_WriteCmd(0xC1);
    ST7735S_WriteData(0xC5);
    ST7735S_WriteCmd(0xC2);
    ST7735S_WriteData(0x0A);
    ST7735S_WriteData(0x00);
    ST7735S_WriteCmd(0xC3);
    ST7735S_WriteData(0x8A);
    ST7735S_WriteData(0x2A);
    ST7735S_WriteCmd(0xC4);
    ST7735S_WriteData(0x8A);
    ST7735S_WriteData(0xEE);
    ST7735S_WriteCmd(0xC5);
    ST7735S_WriteData(0x0E);
    ST7735S_WriteCmd(0x36);
    ST7735S_WriteData(0xC8);
    ST7735S_WriteCmd(0xe0);
    ST7735S_WriteData(0x0f);
    ST7735S_WriteData(0x1a);
    ST7735S_WriteData(0x0f);
    ST7735S_WriteData(0x18);
    ST7735S_WriteData(0x2f);
    ST7735S_WriteData(0x28);
    ST7735S_WriteData(0x20);
    ST7735S_WriteData(0x22);
    ST7735S_WriteData(0x1f);
    ST7735S_WriteData(0x1b);
    ST7735S_WriteData(0x23);
    ST7735S_WriteData(0x37);
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(0x07);
    ST7735S_WriteData(0x02);
    ST7735S_WriteData(0x10);
    ST7735S_WriteCmd(0xe1);
    ST7735S_WriteData(0x0f);
    ST7735S_WriteData(0x1b);
    ST7735S_WriteData(0x0f);
    ST7735S_WriteData(0x17);
    ST7735S_WriteData(0x33);
    ST7735S_WriteData(0x2c);
    ST7735S_WriteData(0x29);
    ST7735S_WriteData(0x2e);
    ST7735S_WriteData(0x30);
    ST7735S_WriteData(0x30);
    ST7735S_WriteData(0x39);
    ST7735S_WriteData(0x3f);
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(0x07);
    ST7735S_WriteData(0x03);
    ST7735S_WriteData(0x10);
    ST7735S_WriteCmd(0x2a);
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(0x7f);
    ST7735S_WriteCmd(0x2b);
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(0x9f);
    ST7735S_WriteCmd(0xF0);
    ST7735S_WriteData(0x01);
    ST7735S_WriteCmd(0xF6);
    ST7735S_WriteData(0x00);
    ST7735S_WriteCmd(0x3A);
    ST7735S_WriteData(0x05);
    ST7735S_WriteCmd(0x29);
    ST7735S_WriteCmd(0x36); // 内存数据访问控制  MX 列地址顺序, MY 行地址顺序 ，MV 行列交换 ，ML 垂直刷新顺序 ,RGB  RGB-BGA顺序
    ST7735S_WriteData(0xc8);//0xc8  0xA8 0x08 0x68
}

void ST7735S_SetAddress(uint8_t site_x, uint8_t site_y, uint8_t size_x, uint8_t size_y) {
    ST7735S_WriteCmd(0x2a);   //Partial Mode On  局部模式
    ST7735S_WriteData(0x00); //高8位 Sx
    ST7735S_WriteData(site_x);   //低8位 Sx
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(site_x + size_x - 1);

    ST7735S_WriteCmd(0x2B);//Row Address Set  行地址设置
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(site_y);
    ST7735S_WriteData(0x00);
    ST7735S_WriteData(site_y + size_y - 1);

    ST7735S_WriteCmd(0x2C);
}

void LCD_Clear(uint16_t Color) {
    ST7735S_SetAddress(2, 2, Lcd_Width - 1, Lcd_Height - 1);
    for (int i = 0; i < Pixel_Cnt - 1; i++) {
        ST7735S_WriteColor(Color);
    }

}

void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t Color) {
    ST7735S_SetAddress(x, y, x, y);
    ST7735S_WriteColor(Color);
}
