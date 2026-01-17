#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>


int main (void) {

	uint16_t n;

	scanf("%"SCNu16, &n);
	printf("%"PRIu16"\n", n);

	return EXIT_SUCCESS;
}
