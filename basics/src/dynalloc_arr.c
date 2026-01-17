#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


/******** FUNCS ********/

struct Array {
	size_t len;
	int *data;
};



struct Array Array_Concat (
	const struct Array *a,
	const struct Array *b
) {
	struct Array c;
	c.len = a->len + b->len;
	c.data = calloc(c.len, sizeof(*c.data));

	for (size_t i = 0; i < a->len; ++i)
		c.data[i] = a->data[i];
	for (size_t i = 0; i < b->len; ++i)
		c.data[a->len+i] = b->data[i];
	return c;
}




/******** MAIN ********/


// err handler
int err (const char *mes) {
	fprintf(stderr, "<ERROR>: %s\n", mes);
	return EXIT_FAILURE; 
}


// main
int main (void) {

	struct Array a = {4, (int[]){1,2,3,4}};
	struct Array b = {3, (int[]){5,6,7}};

	struct Array c = Array_Concat(&a, &b);
	for (size_t i = 0; i < c.len; ++i)
		printf("%d, ", c.data[i]);
	printf("\n");

	free(c.data);
	return EXIT_SUCCESS;
}

