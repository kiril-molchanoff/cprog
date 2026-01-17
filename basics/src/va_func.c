#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <stdarg.h>


int sum (size_t n, ...) {
	va_list ptr;		// declare empty ptr
	va_start(ptr, n);	// set ptr to next arg

	int res = 0;
	for (size_t i = 0; i < n; ++i)
		res += va_arg(ptr, int);

	va_end(ptr);		// free resourses
	return res;
}




// MAIN
int main (void) {

	printf("%d\n", sum(6, 1, 2, 3, 4, 5, 6));

	return 0;
}
