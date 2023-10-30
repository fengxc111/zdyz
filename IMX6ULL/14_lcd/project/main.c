#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_keyfilter.h"
#include "bsp_uart.h"
#include "bsp_lcd.h"
#include "bsp_lcdapi.h"
#include "stdio.h"

unsigned int backcolor[10] = {
	LCD_BLUE, 		LCD_GREEN, 		LCD_RED, 	LCD_CYAN, 	LCD_YELLOW, 
	LCD_LIGHTBLUE, 	LCD_DARKBLUE, 	LCD_WHITE, 	LCD_BLACK, 	LCD_ORANGE

}; 

int main()
{
    unsigned char index = 0;
	tftlcd_dev.forecolor = LCD_RED;

    int_init();
    imx6u_clkinit();
    delay_init();
    clk_enable();
    uart_init();

    led_init();
    beep_init();
    key_init();
    lcd_init();

    unsigned char state = OFF;
    while(1)
    {
        lcd_clear(backcolor[index]);
		delay_ms(1); 	  
		lcd_show_string(10, 40, 260, 32, 32,(char*)"ALPHA IMX6U"); 	
		lcd_show_string(10, 80, 240, 24, 24,(char*)"RGBLCD TEST");
		lcd_show_string(10, 110, 240, 16, 16,(char*)"ATOM@ALIENTEK");      					 
		lcd_show_string(10, 130, 240, 12, 12,(char*)"2019/8/14");

        state = !state;
        index += 1;
        index %= 10;

        led_switch(LED0, state);
        delay_ms(1000);
        
#if 0
		index++;
		if(index == 10)
			index = 0;
		lcd_fill(0, 300, 1023, 599, backcolor[index]);
		lcd_show_string(800,10,240,32,32,(char*)"INDEX=");  /*显示字符串				  */
		lcd_shownum(896,10, index, 2, 32); 					/* 显示数字，叠加显示	*/
		
		state = !state;
		led_switch(LED0,state);
		delayms(1000);	/* 延时一秒	*/
#endif
    }

    return 0;
}