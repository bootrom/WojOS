#include <stdio.h>
#include "libc_stdio.h"
//#include "uart_dev.h"
#include "drivers/uart.h"

//avr-libc provides fdevopen which takes a function pointer to a user defined putc function. 
//Else we can use the fdev_setup_stream macro to create our own stdin/stdout definitions.

void stdioInit()
{
	uartInit();
}
