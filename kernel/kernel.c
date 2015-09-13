#include <stdlib.h>
#include <stdio.h>
#include "kernel.h"

void * task_spawn(void (*taskPointer)())
{
	uint8_t *stack = malloc(STACK_SIZE);
	if (NULL == stack)
		return -1;
	
	stack += STACK_SIZE;

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

void taskScheduleInit() {
	//Setup a timer
}
