
#include "avr/io.h"
#include "util/delay.h"
//#include "drivers/uart.h"

#define	TICK	1

int board_init()
{
	//uartInit();
	return 0;
}

void task_spawn(void *stackBase, int stackSize, void (*taskPointer)(void *, void*))
{
	
}

void task2()
{
	//puts("This is task2\n", sizeof("this is task2\n");
}

int main()
{
	board_init();
	
	//task_spawn();

	while (1)
	{
		//task_switch();
		_delay_ms(1000);
	}
	
	return 0;
}
