// ---------------------------------------------------------------------------
// Created by Francisco Malpartida on 20/08/11.
// Copyright 2011 - Under creative commons license 3.0:
//        Attribution-ShareAlike CC BY-SA
//
// This software is furnished "as is", without technical support, and with no 
// warranty, express or implied, as to its usefulness for any purpose.
//
// Thread Safe: No
// Extendable: Yes
//
// @file LiquidCrystal.cpp
// This file implements a basic liquid crystal library that comes as standard
// in the Arduino SDK.
// 
// @brief 
// This is a basic implementation of the LiquidCrystal library of the
// Arduino SDK. The original library has been reworked in such a way that 
// this class implements the all methods to command an LCD based
// on the Hitachi HD44780 and compatible chipsets using the parallel port of
// the LCD (4 bit and 8 bit).
//
// The functionality provided by this class and its base class is identical
// to the original functionality of the Arduino LiquidCrystal library.
//
//
// @author F. Malpartida - fmalpartida@gmail.com
// ---------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "LiquidCrystal.h"

// CONSTANT  definitions
// ---------------------------------------------------------------------------
#define LCD_NOBACKLIGHT 0xFF

// LCD driver configuration (4bit or 8bit driver control)
#define LCD_4BIT                1
#define LCD_8BIT                0

// STATIC helper functions
// ---------------------------------------------------------------------------


// CONSTRUCTORS
// ---------------------------------------------------------------------------

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t enable,
                             uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                             uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
   init(LCD_8BIT, rs, 255, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
                             uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                             uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
   init(LCD_8BIT, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
                             uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
   init(LCD_4BIT, rs, rw, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

LiquidCrystal::LiquidCrystal(uint8_t rs,  uint8_t enable,
                             uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
   init(LCD_4BIT, rs, 255, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

// Contructors with backlight control
LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t enable,
                             uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                             uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7,
                             uint8_t backlightPin, t_backlighPol pol)
{
   init(LCD_8BIT, rs, 255, enable, d0, d1, d2, d3, d4, d5, d6, d7);
   setBacklightPin ( backlightPin, pol );
}

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
                             uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                             uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7,
                             uint8_t backlightPin, t_backlighPol pol)
{
   init(LCD_8BIT, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
   setBacklightPin ( backlightPin, pol );
}

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
                             uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                             uint8_t backlightPin, t_backlighPol pol)
{
   init(LCD_4BIT, rs, rw, enable, d0, d1, d2, d3, 0, 0, 0, 0);
   setBacklightPin ( backlightPin, pol );
}

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t enable,
                             uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                             uint8_t backlightPin, t_backlighPol pol)
{
   init(LCD_4BIT, rs, 255, enable, d0, d1, d2, d3, 0, 0, 0, 0);
   setBacklightPin ( backlightPin, pol );
}

// PUBLIC METHODS
// ---------------------------------------------------------------------------

/************ low level data pushing commands **********/
//
// send
void LiquidCrystal::send(uint8_t value, uint8_t mode) 
{
}

//
// setBacklightPin
void LiquidCrystal::setBacklightPin ( uint8_t pin, t_backlighPol pol )
{
}

//
// setBackligh
void LiquidCrystal::setBacklight ( uint8_t value )
{
}

// PRIVATE METHODS
// ---------------------------------------------------------------------------


// init
void LiquidCrystal::init(uint8_t fourbitmode, uint8_t rs, uint8_t rw, uint8_t enable,
                         uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                         uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
}

//
// pulseEnable
void LiquidCrystal::pulseEnable(void) 
{
}

//
// write4bits
void LiquidCrystal::writeNbits(uint8_t value, uint8_t numBits) 
{
}


