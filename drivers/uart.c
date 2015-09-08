#include "uart.h"
#include "avr/io.h"

void uartInit()
{
	UCSR0C = CHAR_SIZE;
	UBRR0L = BAUD_RATE_9600;
	UBRR0H = 0x0;
	UCSR0B = 0x18;//UART_ENABLE;
}

int uartTx(char txByte, int blocking)
{
	
	UDR0 = txByte;

	//Block until tranmit complete
	if (blocking)
		while (!(UCSR0A & TX_FINISHED)) {}
	return 0;
}

int uartRx(char rxByte, int blocking)
{
	//fill this out
	return 0;
} 

/*
int uartTx(char* txByte)
{
	
	while (*txByte) {
		while (!(UCSR0A & UDR_EMPTY)) {}

		UDR0 = *txByte;
	
		// Block until transmit complete flag	
		while (!(UCSR0A & TX_FINISHED)) {}
		txByte++;
	}
	return 1;
}
*/
