#include "avr/io.h"
#include <stdio.h>
#include "util/delay.h"
#include "drivers/uart.h"
#include "arch/avr/libc_stdio.h"
#include "arch/avr/platform.h"
#include "arch/avr/task.h"
#include <stdlib.h>

#define	TICK	1
#define CONTEXT_SIZE	36

static void *primaryStackPtr = NULL;
static void *secondStackPtr = NULL;
uint8_t secondStack[128];

void taskSwitch(void** curTask, void* nextTask);

int board_init()
{
	stdioInit();
	platform_init();
	//uartInit();
	return 0;
}

void task2()
{
	while (1)
	{
		printf("task2 printf\n");
		malloc(20);
		//uartTx('b', 1);
		//uartTx("task2\n");
		//puts("This is task2\n", sizeof("this is task2\n");
		taskSwitch(&secondStackPtr, primaryStackPtr);
		_delay_ms(5000);
	}
}

int main()
{
	board_init();
	
	//secondStackPtr = task_spawn(secondStack, sizeof(secondStack), task2);
	secondStackPtr = task_spawn(task2);

	while (1)
	{
		printf("main task printf\n");
		//uartTx('a', 1);
		//uartTx("main\n");
		taskSwitch(&primaryStackPtr, secondStackPtr);
		_delay_ms(5000);
	}
	
	return 0;
}
