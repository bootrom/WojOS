#include "uart.h"
#include "avr/io.h"

int uartInit()
{
	UCSR0C = CHAR_SIZE;
	UBRR0L = BAUD_RATE_9600;
	UBRR0H = 0x0;
	UCSR0B = UART_ENABLE;

	return 0;
}

int uartTx(uint8_t txByte)
{
	if (UCSR0A & UDR_EMPTY)
		UDR0 = txByte;
	else
		return 0;

	return 1;
}
