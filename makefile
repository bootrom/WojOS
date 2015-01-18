CROSS_COMPILE=avr-gcc
CFLAGS=-Wall -I. -L.

board: board.o

clean:
	rm -f board board.o
#Libraries to add:
#/usr/lib/avr/lib
