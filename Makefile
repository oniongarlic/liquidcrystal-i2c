HEADERS=I2CIO.h LCD.h LiquidCrystal_I2C.h

SRC=I2CIO.cpp LCD.cpp LiquidCrystal_I2C.cpp

OBJ=$(SRC:.cpp=.o)
STATIC=lci2c.a
LDFLAGS=-L/usr/local/lib -lwiringPi 

CC=g++

all: static main

main.o: main.cpp

main: main.o $(OBJ) 

static:	$(STATIC)

$(OBJ): $(SRC) $(HEADERS)

$(STATIC): $(OBJ)
	ar rcs $(STATIC) $(OBJ)
	ranlib $(STATIC)

clean:
	rm -f *.o main
