#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <util/delay.h>

#include "lcd_display.h"

char tab1[] = {"Kocham "};
const char PROGMEM tab2[] = "Cie";
char tab3[] = "Karolciu!";
char tab4[] = "<3<3";
uint8_t custom_e[] = {0, 0, 14, 17, 31, 16, 15, 2};

int main(void) {
  lcd_init();
  lcd_defchar(0x80, custom_e);
  
  
  while (1) {
    lcd_cls();
    lcd_str(tab1);
    _delay_ms(1000);
    lcd_str_P(tab2);
    //lcd_str("\x80");
    _delay_ms(1000);
    lcd_cls();
    lcd_str(tab3);
    _delay_ms(1000);
    lcd_str(tab4);
    _delay_ms(1000);   
  }
}
