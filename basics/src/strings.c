#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>


void str_print(const char* str) {
	while (*str != '\0')
		printf("\'%c\' ", *str++);
	printf("\n");
}


int main (void) {

	// string literal arr
	const char* a[] = {"red", "green", "yellow", "blue", "purple"};
	const size_t n = sizeof(a) / sizeof(*a);
	
	for (size_t i = 0; i < n; ++i)
		str_print(a[i]);

	return 0;
}
