/**
 ** i2c LCD test application
 **
 ** Author: Kaj-Michael Lang <milang@tal.org>
 ** Copyright 2014 - Under creative commons license 3.0 Attribution-ShareAlike CC BY-SA
 **/
#include "LiquidCrystal_I2C.h"

int main (int argc, char *argv []) {
// i2c address
uint8_t i2c=0x27;
// Control line PINs
uint8_t en=2;
uint8_t rw=1;
uint8_t rs=0;

// Data line PINs
uint8_t d4=4;
uint8_t d5=5;
uint8_t d6=6;
uint8_t d7=7;

// Backlight PIN
uint8_t bl=3;

// LCD display size
uint8_t rows=2;
uint8_t cols=8;

LiquidCrystal_I2C lcd(i2c, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

lcd.begin(cols, rows);

lcd.on();
lcd.clear();

lcd.print("ABCDEFGH");
lcd.setCursor(0, 1);
lcd.print("12345678");

sleep(2);

lcd.clear();
lcd.write('H');
lcd.write('e');
lcd.write('l');
lcd.write('l');
lcd.write('o');
lcd.setCursor(0, 1);
lcd.write('W');
lcd.write('o');
lcd.write('r');
lcd.write('l');
lcd.write('d');
lcd.write('!');

sleep(2);
lcd.blink();
sleep(2);

lcd.home();
lcd.cursor();
lcd.autoscroll();
// lcd.setCursor(15,1);
for (uint8_t i=33; i<=126; i++) {
	lcd.write((char)i);
}
sleep(1);
lcd.noBlink();
lcd.noCursor();
sleep(1);
lcd.clear();
}
