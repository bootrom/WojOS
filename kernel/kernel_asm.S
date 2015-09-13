#define __SFR_OFFSET 0
#include "avr/io.h"

	.text
	.p2align	2
	.global		taskSwitch
taskSwitch:
	PUSH r0
	PUSH r1
	PUSH r2
	PUSH r3
	PUSH r4
	PUSH r5
	PUSH r6
	PUSH r7
	PUSH r8
	PUSH r9
	PUSH r10
	PUSH r11
	PUSH r12
	PUSH r13
	PUSH r14
	PUSH r15
	PUSH r16
	PUSH r17
	PUSH r18
	PUSH r19
	PUSH r20
	PUSH r21
	PUSH r22
	PUSH r23
	PUSH r24
	PUSH r25
	PUSH r26
	PUSH r27
	PUSH r28
	PUSH r29
	PUSH r30
	PUSH r31

	// Cannot directly push SREG
	IN r0, SREG
	PUSH r0

	// Clear global interrupts
	CLI
	IN r16, SPL
	IN r17, SPH

	// Save the current tasks stack pointer to the 
	// location passed in as argument 1
	MOV R26, r24 // Argument 1 byte0 to X reg lower address
	MOV R27, r25 // Argument 1 byte1 to X reg upper address
	ST  X+, r16  // Store SPL and post increment 1 byte
	ST  X, r17    // Store SPH

	// Now we need to load in argument 2 the secondary stacks
	// address for the next task
	OUT SPL, r22 // Argument 2 byte0 	
	OUT SPH, r23 // Argument 2 byte1
	
	POP R0
	OUT SREG, R0
	POP R31
	POP R30
	POP R29
	POP R28
	POP R27
	POP R26
	POP R25
	POP R24
	POP R23
	POP R22
	POP R21
	POP R20
	POP R19
	POP R18
	POP R17
	POP R16
	POP R15
	POP R14
	POP R13
	POP R12
	POP R11
	POP R10
	POP R9
	POP R8
	POP R7
	POP R6
	POP R5
	POP R4
	POP R3
	POP R2
	POP R1
	POP R0

	// Return and enable interrupts, grabs return
	// address from the last 2 stack pushes.
	RETI
	

