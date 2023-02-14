#include "SSD1289.h"

void SSD1289_WriteCmd(uint16_t CMD) {
    SSD1289_CMD;
    SSD1289_WR_LO;
    SSD1289_WRITE(CMD);
    SSD1289_WR_HI;
}

void SSD1289_WriteData(uint16_t DATA) {
    SSD1289_DATA;
    SSD1289_WR_LO;
    SSD1289_WRITE(DATA);
    SSD1289_WR_HI;
}

void SSD1289_WriteCmdData(uint16_t CMD, uint16_t DATA) {
    SSD1289_WriteCmd(CMD);
    SSD1289_WriteData(DATA);
}

void SSD1289_WriteColor(uint16_t Color) {
    SSD1289_WR_LO;
    SSD1289_WRITE(Color);
    SSD1289_WR_HI;
}

void SSD1289_SetAddress(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t end_y) {
#if (HORIZONTAL)
    SSD1289_WriteCmdData(0x0044, (end_y << 8) + start_y);
    SSD1289_WriteCmdData(0x0045, Lcd_Width - end_x - 1);
    SSD1289_WriteCmdData(0x0046, Lcd_Width - start_x - 1);
    SSD1289_WriteCmdData(0x004E, start_y);
    SSD1289_WriteCmdData(0x004F, Lcd_Width - start_x - 1);
    SSD1289_WriteCmd(0x0022);
#else
    SSD1289_WriteCmdData(0x0044, (end_x << 8) + start_x);
    SSD1289_WriteCmdData(0x0045, start_y);
    SSD1289_WriteCmdData(0x0046, end_y);
    SSD1289_WriteCmdData(0x004E, start_x);
    SSD1289_WriteCmdData(0x004F, start_y);
    SSD1289_WriteCmd(0x0022);
#endif
}

void LCD_Clear(uint16_t color) {
    SSD1289_SetAddress(0, 0, Lcd_Width - 1, Lcd_Height - 1);
    SSD1289_DATA;
    for (int i = 0; i < Pixel_Cnt - 1; i++) {
        SSD1289_WriteColor(color);
    }
}

void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t Color) {
    SSD1289_SetAddress(x, y, x, y);
    SSD1289_WriteData(Color);
}

void LCD_init(void) {
    SSD1289_CS_LO;
    SSD1289_WriteCmdData(0x0007, 0x0021);
    SSD1289_WriteCmdData(0x0000, 0x0001);
    SSD1289_WriteCmdData(0x0007, 0x0023);
    SSD1289_WriteCmdData(0x0010, 0x0000);
    //Delay(30);
    SSD1289_WriteCmdData(0x0007, 0x0033);
#if HORIZONTAL
    SSD1289_WriteCmdData(0x0011, 0x6058);
#else
    SSD1289_WriteCmdData(0x0011, 0x6070);
#endif
    SSD1289_WriteCmdData(0x0002, 0x1000);
    SSD1289_WriteCmdData(0x0002, 0x0600);
    SSD1289_WriteCmdData(0x0001, 0x693f);//0x6b3f,显示方向
    SSD1289_WriteCmdData(0x0016, 0xef1c);//每行有效像素
    SSD1289_WriteCmdData(0x0025, 0xef00);//帧率控制
    SSD1289_WriteCmdData(0x0030, 0x0007);
    SSD1289_WriteCmdData(0x0031, 0x0302);
    SSD1289_WriteCmdData(0x0032, 0x0105);
    SSD1289_WriteCmdData(0x0033, 0x0206);
    SSD1289_WriteCmdData(0x0034, 0x0808);
    SSD1289_WriteCmdData(0x0035, 0x0206);
    SSD1289_WriteCmdData(0x0036, 0x0504);
    SSD1289_WriteCmdData(0x0037, 0x0007);
    SSD1289_WriteCmdData(0x003A, 0x0105);
    SSD1289_WriteCmdData(0x003B, 0x0808);
}