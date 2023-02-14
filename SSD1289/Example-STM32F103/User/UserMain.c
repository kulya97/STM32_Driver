#include "UserMain.h"
#include "stdlib.h"
#include <stdio.h>
#include "SSD1289.h"
#include "image.h"

/*********************************************************************************/
extern UART_HandleTypeDef huart1;
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)   //STM32CubeIDE
#else

#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)  //Keil

#endif

PUTCHAR_PROTOTYPE {

    HAL_UART_Transmit(&huart1, (uint8_t *) &ch, 1, HAL_MAX_DELAY);
    return ch;
}

int _write(int file, char *ptr, int len) {
    int DataIdx;

    for (DataIdx = 0; DataIdx < len; DataIdx++) {
        __io_putchar(*ptr++);
    }

    return len;
}
/*********************************************************************************/
////Transfer GuiLite 32 bits color to your LCD color
//#define GL_RGB_32_to_16(rgb) (((((unsigned int)(rgb)) & 0xFF) >> 3) | ((((unsigned int)(rgb)) & 0xFC00) >> 5) | ((((unsigned int)(rgb)) & 0xF80000) >> 8))
//
////Encapsulate your LCD driver:
//void gfx_draw_pixel(int x, int y, unsigned int rgb) {
//    LCD_DrawPixel(x, y, GL_RGB_32_to_16(rgb));
//}
//
////Implement it, if you have more fast solution than drawing pixels one by one.
////void gfx_fill_rect(int x0, int y0, int x1, int y1, unsigned int rgb){}
//void delay_ms(unsigned short nms) {
//    HAL_Delay(nms);
//}
//
////UI entry
//struct DISPLAY_DRIVER {
//    void (*draw_pixel)(int x, int y, unsigned int rgb);
//
//    void (*fill_rect)(int x0, int y0, int x1, int y1, unsigned int rgb);
//} my_driver;
//
//extern void startHello3D(void *phy_fb, int width, int height, int color_bytes, struct DISPLAY_DRIVER *driver);
/*********************************************************************************/
/*
 * 配置参数初始化
 */
void UserConfigInit() {

}

/*
 * 系统初始化
 */
void UserSysInit() {
    LCD_init();
    // LCD_Clear(0xF800);
//    SSD1289_SetAddress(0, 0, Lcd_Width - 1, Lcd_Height - 1);
//    SSD1289_DATA;
//    for (int i = 0; i < 46800 - 1; i++) {
//        SSD1289_WriteColor(gImage_image[2 * i] << 8 | gImage_image[2 * i + 1]);
//    }
    //LCD_Clear(0xF800);
//    my_driver.draw_pixel = gfx_draw_pixel;
//    my_driver.fill_rect = NULL;//gfx_fill_rect;
//    startHello3D(NULL, 240, 320, 2, &my_driver);
}

/*
 * 主循环,任务分发
 */
void UserLoop() {
//    SSD1289_SetAddress(0, 0, 320 - 1 , 240 - 1 );
//    SSD1289_DATA;
//    for (int i = 0; i < 76800 - 1; i++) {
//        SSD1289_WriteColor(gImage_image[2 * i] << 8 | gImage_image[2 * i + 1]);
//    }
    uint16_t static color = 0;
    color = color + 1000;
    LCD_Clear(color);
    // uint16_t id=LCD_Read_ID();
    //printf("%02x\n",id);
}

