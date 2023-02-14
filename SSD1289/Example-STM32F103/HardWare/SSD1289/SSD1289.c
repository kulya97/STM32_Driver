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

uint8_t SSD1289_SetAddress(uint16_t pos_x, uint16_t pos_y, uint16_t window_width, uint16_t window_high) {
    if (pos_x < 0 || pos_y < 0 || window_width < 0 || window_high < 0) { return 1; }
    if (pos_x + window_width > Lcd_Width) { return 1; }
    if (pos_y + window_high > Lcd_Height) { return 1; }
#if (HORIZONTAL)
    SSD1289_WriteCmdData(0x0044, ((pos_y + window_high - 1) << 8) + pos_y);
    SSD1289_WriteCmdData(0x0045, Lcd_Width - pos_x - window_width);
    SSD1289_WriteCmdData(0x0046, Lcd_Width - pos_x - 1);
    SSD1289_WriteCmdData(0x004E, pos_y);
    SSD1289_WriteCmdData(0x004F, Lcd_Width - pos_x - 1);
    SSD1289_WriteCmd(0x0022);
#else
    SSD1289_WriteCmdData(0x0044, ((pos_x + window_width - 1) << 8) + pos_x);
    SSD1289_WriteCmdData(0x0045, pos_y);
    SSD1289_WriteCmdData(0x0046, pos_y + window_high - 1);
    SSD1289_WriteCmdData(0x004E, pos_x);
    SSD1289_WriteCmdData(0x004F, pos_y);
    SSD1289_WriteCmd(0x0022);
#endif
    SSD1289_DATA;
    return 0;
}

void LCD_Clear(uint16_t color) {
    SSD1289_SetAddress(0, 0, Lcd_Width, Lcd_Height);
    for (int i = 0; i < Pixel_Cnt - 1; i++) {
        SSD1289_WriteColor(color);
    }
}

void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t Color) {
    SSD1289_SetAddress(x, y, 1, 1);
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
    SSD1289_WriteCmdData(0x0016, 0xef1c);//每行有效像素 240
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