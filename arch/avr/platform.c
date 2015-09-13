#include <stdlib.h>
#include <stdio.h>

extern void *malloc(size_t __size);

void _malloc(size_t __size) {
	printf("malloc\n");
}

void platform_init() {
	void (*malloc)(size_t) = _malloc;
}
