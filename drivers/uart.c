#include "uart.h"
#include "/avr/io.h"

int uartInit()
{
	UCSR0C = (CHAR_SIZE < 1);

#ifdef F_CPU
}
