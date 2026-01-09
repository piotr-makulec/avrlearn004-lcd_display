//Piotr Makulec, 2025
//Written for and tested on Arduino (ATmega328p).

//Displaying a message on the JHD162A LCD display.

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <util/delay.h>

#include "lcd_display.h"

#define EEMEM __attribute__((section(".eeprom"))) //saving the string to EEPROM - tbd

char tab1[] = {"Kocham "};
const char tab2[] PROGMEM = "Ci"; //the string is saved into the FLASH memory
char tab3[] = "Karolciu";

uint8_t custom_e[] = {0, 0, 14, 17, 31, 16, 15, 2};
uint8_t custom_heart[] = {0, 10, 31, 31, 31, 14, 4};

int main(void) {
  //initialization
  lcd_init();
  //saving custom characters to CGRAM 
  lcd_defchar(0x01, custom_e);
  lcd_defchar(0x02, custom_heart);
  
  while (1) {
    lcd_cls();
    _delay_ms(1000); 
    lcd_locate(0, 3);
    lcd_str(tab1);
    _delay_ms(1000);
    lcd_str_P(tab2);
    lcd_str("\x01");
    _delay_ms(1000);
    lcd_locate(1, 2);
    lcd_str(tab3);
    _delay_ms(1000);
    lcd_str(" \x02\x02\x02");
    _delay_ms(1000);   
  }
}
