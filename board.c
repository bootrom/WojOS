#include "avr/io.h"
#include "stdlib.h"
#include <stdio.h>
#include "util/delay.h"
#include "drivers/uart.h"
#include "arch/avr/libc_stdio.h"

#define	TICK	1
#define CONTEXT_SIZE	36

static void *primaryStackPtr = NULL;
static void *secondStackPtr = NULL;
uint8_t secondStack[128];

void taskSwitch(void** curTask, void* nextTask);

int board_init()
{
	stdioInit();
	//uartInit();
	return 0;
}

void * task_spawn(void *stackBase, int stackSize, void (*taskPointer)())
{
	uint8_t *stack = stackBase + stackSize; // AVR stack grows down

	stack[-1] = (uint8_t)((uintptr_t)taskPointer >> 0);
	stack[-2] = (uint8_t)((uintptr_t)taskPointer >> 8);
	stack[-3] = (uint8_t)'s'; // R0
	stack[-4] = (uint8_t)0x0; // R1, should always hold the value 0
	stack[-5] = (uint8_t)'s'; // R2
	stack[-6] = (uint8_t)'s'; // R3
	stack[-7] = (uint8_t)'s'; // R4
	stack[-8] = (uint8_t)'s'; // R5
	stack[-9] = (uint8_t)'s'; // R6
	stack[-10] = (uint8_t)'s'; // R7
	stack[-11] = (uint8_t)'s'; // R8
	stack[-12] = (uint8_t)'s'; // R9
	stack[-13] = (uint8_t)'s'; // R10
	stack[-14] = (uint8_t)'s'; // R11
	stack[-15] = (uint8_t)'s'; // R12
	stack[-16] = (uint8_t)'s'; // R13
	stack[-17] = (uint8_t)'s'; // R14
	stack[-18] = (uint8_t)'s'; // R15
	stack[-18] = (uint8_t)'s'; // R16
	stack[-19] = (uint8_t)'s'; // R17
	stack[-20] = (uint8_t)'s'; // R18
	stack[-21] = (uint8_t)'s'; // R19
	stack[-22] = (uint8_t)'s'; // R20
	stack[-23] = (uint8_t)'s'; // R21
	stack[-24] = (uint8_t)'s'; // R22
	stack[-25] = (uint8_t)'s'; // R23
	stack[-26] = (uint8_t)'s'; // R24
	stack[-27] = (uint8_t)'s'; // R24
	stack[-28] = (uint8_t)'s'; // R25
	stack[-29] = (uint8_t)'s'; // R26
	stack[-30] = (uint8_t)'s'; // R27
	stack[-31] = (uint8_t)'s'; // R28
	stack[-32] = (uint8_t)'s'; // R29
	stack[-33] = (uint8_t)'s'; // R30
	stack[-34] = (uint8_t)'s'; // R31
	stack[-35] = (uint8_t)0x0; // Disable interrupts within SREG

	return stack - CONTEXT_SIZE;
}

void task2()
{
	while (1)
	{
		printf("task2 printf\n");
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
	
	secondStackPtr = task_spawn(secondStack, sizeof(secondStack), task2);
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
