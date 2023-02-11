#include "SSD1289.h"

void SSD1289_WriteCmd(uint16_t CMD) {
    SSD1289_RD_HI;
    SSD1289_CMD;
    SSD1289_WR_LO;
    SSD1289_CS_LO;
    SSD1289_WRITE(CMD);
    SSD1289_CS_HI;
}
void SSD1289_WriteData(uint16_t DATA) {
    SSD1289_RD_HI;
    SSD1289_DATA;
    SSD1289_WR_LO;
    SSD1289_CS_LO;
    SSD1289_WRITE(DATA);
    SSD1289_CS_HI;
}
void SSD1289_WriteCmdData(uint16_t CMD, uint16_t DATA) {
    SSD1289_WriteCmd(CMD);
    SSD1289_WriteData(DATA);
}

void SSD1289_WriteColorInit(void) {
    SSD1289_RD_HI;
    SSD1289_DATA;
    SSD1289_WR_LO;
}
void SSD1289_WriteColor(uint16_t Color) {
    SSD1289_CS_LO;
    SSD1289_WRITE(Color);
    SSD1289_CS_HI;
}

void SSD1289_SetAddress(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    SSD1289_WriteCmdData(0x0044, (x2 << 8) + x1);
    SSD1289_WriteCmdData(0x0045, y1);
    SSD1289_WriteCmdData(0x0046, y2);
    SSD1289_WriteCmdData(0x004E, x1);
    SSD1289_WriteCmdData(0x004F, y1);
    SSD1289_WriteCmd(0x0022);
}

void LCD_Clear(uint16_t color) {
    SSD1289_SetAddress(0, 0, Lcd_Width - 1, Lcd_Height - 1);
    SSD1289_WriteColorInit();
    for (int i = 0; i < Pixel_Cnt-1; i++) {
        SSD1289_WriteColor(color);
    }
}
void LCD_DrawPixel(uint16_t x, uint16_t y,uint16_t Color) {
    SSD1289_SetAddress(x, y, x, y);
    SSD1289_WriteData(Color);
}

void LCD_init(void) {
    SSD1289_WriteCmdData(0x0007, 0x0021);
    SSD1289_WriteCmdData(0x0000, 0x0001);
    SSD1289_WriteCmdData(0x0007, 0x0023);
    SSD1289_WriteCmdData(0x0010, 0x0000);
    Delay(30);
    SSD1289_WriteCmdData(0x0007, 0x0033);
    SSD1289_WriteCmdData(0x0011, 0x6030);
    SSD1289_WriteCmdData(0x0002, 0x1000);
    SSD1289_WriteCmdData(0x0002, 0x600);
    SSD1289_WriteCmdData(0x0001, 0x6B3f);
    SSD1289_WriteCmdData(0x0025, 0x8000);
    SSD1289_WriteCmdData(0x0030, 0x7);
    SSD1289_WriteCmdData(0x0031, 0x302);
    SSD1289_WriteCmdData(0x0032, 0x105);
    SSD1289_WriteCmdData(0x0033, 0x206);
    SSD1289_WriteCmdData(0x0034, 0x808);
    SSD1289_WriteCmdData(0x0035, 0x206);
    SSD1289_WriteCmdData(0x0036, 0x504);
    SSD1289_WriteCmdData(0x0037, 0x7);
    SSD1289_WriteCmdData(0x003A, 0x105);
    SSD1289_WriteCmdData(0x003B, 0x808);
}