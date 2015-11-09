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
uint8_t rows=4;
uint8_t cols=20;

LiquidCrystal_I2C lcd("/dev/i2c-1", i2c, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

lcd.begin(cols, rows);

lcd.on();
lcd.clear();

lcd.print("ABCDEFGH");
lcd.setCursor(0, 1);
lcd.print("12345678");

if (rows>2) {
	lcd.setCursor(0, 2);
	lcd.print("ABCDEFGH");
	lcd.setCursor(0, 3);
	lcd.print("12345678");
}

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

if (rows>2) {
	lcd.setCursor(0,2);
	lcd.print("We say");
	lcd.setCursor(0,3);
	lcd.print("H'ello back!");
}

sleep(2);
lcd.blink();
sleep(2);

lcd.clear();
lcd.cursor();
lcd.autoscroll();
for (uint8_t i=33; i<255; i++) {
	usleep(35000);
	lcd.write((char)i);
	if (i % 8==0)
		sleep(1);
}
sleep(1);
lcd.noBlink();
lcd.noCursor();
sleep(1);
lcd.clear();
}
