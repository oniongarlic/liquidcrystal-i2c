/**
 ** i2c LCD test application
 **
 ** Author: Kaj-Michael Lang <milang@tal.org>
 ** Copyright 2014 - Under creative commons license 3.0 Attribution-ShareAlike CC BY-SA
 **/
#include "LiquidCrystal_I2C.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv [])
{
// GPIO chip i2c address
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

// LCD display size (1x16, 2x16, 4x20)
uint8_t rows=2;
uint8_t cols=16;

int adapter_nr=9;
char filename[20];

if (argc>1) {
	int a=atoi(argv[1]);
	if (a>0 && a<9999)
		adapter_nr=a;
}

snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);

printf("Using i2c device: %s, Rows: %u, Cols: %u\n", filename, rows, cols);

LiquidCrystal_I2C lcd(filename, i2c, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

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

char hw[]="Hello World";

lcd.clear();
lcd.cursor();
lcd.blink();
for (int i=0;i<strlen(hw);i++) {
	lcd.write(hw[i]);
	usleep(20000);
}

sleep(2);
lcd.noBlink();
lcd.noCursor();

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
	if (i % 16==0)
		sleep(1);
}
sleep(1);
lcd.noBlink();
lcd.noCursor();
sleep(1);
lcd.clear();
}
