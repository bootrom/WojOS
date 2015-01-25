#include "avr/io.h"

#define CHAR_SIZE (0x3 << 1)
#define UART_ENABLE (0x3 << 3)
#define BAUD_RATE_9600 0x33
#define UDR_EMPTY (1 << 5)

int uartInit();

int uartTx(uint8_t txByte);
