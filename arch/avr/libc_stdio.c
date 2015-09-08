#include <stdio.h>
#include "libc_stdio.h"
//#include "uart_dev.h"
#include "drivers/uart.h"

//avr-libc provides fdevopen which takes a function pointer to a user defined putc function. 
//Else we can use the fdev_setup_stream macro to create our own stdin/stdout definitions.

//According to avr-libc it looks like the fdevopen option requires malloc, which is not yet
//implemented. May be easier to just use the macro to define a file stream.

//Forward declarations
static int _putc(int c, FILE *stream);
static int _getc(FILE *stream);

static FILE _stdin = FDEV_SETUP_STREAM(NULL, _getc, _FDEV_SETUP_READ);
static FILE _stdout = FDEV_SETUP_STREAM(_putc, NULL, _FDEV_SETUP_WRITE);

void stdioInit()
{
	uartInit();
	
	//Setup the stdio streams to point to this architectures implementaion
	stdin = &_stdin;
	stdout = &_stdout;
	stderr = &_stdout;
}

static int _putc(int c, FILE *stream)
{
	if ((stream == stdout) || (stream == stderr))
		return uartTx(c, 1);
	else
		return -1;
}

static int _getc(FILE *stream)
{	
	char c;
	return uartRx(c, 1);
}
