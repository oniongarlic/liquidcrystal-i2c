HEADERS=I2CIO.h LCD.h LiquidCrystal_I2C.h
SRC=I2CIO.cpp LCD.cpp LiquidCrystal_I2C.cpp

OBJ=$(SRC:.cpp=.o)
STATIC=libliquidcrystali2c.a
LDFLAGS=-L /usr/lib/x86_64-linux-gnu/ -li2c

CFLAGS=-ggdb -O2

CC=g++

PREFIX=/usr/local

all: static test-lcd

main.o: main.cpp

test-lcd: main.o $(OBJ)
	$(CC) -o test-lcd main.o libliquidcrystali2c.a $(LDFLAGS)

static:	$(STATIC)

$(OBJ): $(SRC) $(HEADERS)

$(STATIC): $(OBJ)
	ar rcs $(STATIC) $(OBJ)
	ranlib $(STATIC)

install: all
	install -d -m 755 $(PREFIX)/lib
	install -d -m 755 $(PREFIX)/include/liquidcrystal

	install -m 644 $(STATIC) $(PREFIX)/lib/
	install -m 644 $(HEADERS) $(PREFIX)/include/liquidcrystal

clean:
	rm -f *.o main
