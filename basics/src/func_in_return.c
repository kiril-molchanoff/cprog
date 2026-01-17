#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


typedef int64_t bin_op (int64_t, int64_t);

int64_t add (int64_t a, int64_t b) { return a + b; }
int64_t sub (int64_t a, int64_t b) { return a - b; }
int64_t mult (int64_t a, int64_t b) { return a * b; }

enum op_name {
	ADD,
	SUB,
	MULT
};


bin_op *select_op (enum op_name opt) {

	switch (opt) {
		case ADD:
			return add;
		case SUB:
			return sub; 
		case MULT:
			return mult; 
		default:
			return NULL;
	}
}


// MAIN
int main (void) {
	
	int64_t a = 4;
	int64_t b = 5;

	printf("add: %ld\n", select_op(ADD)(a, b));
	printf("sub: %ld\n", select_op(SUB)(a, b));
	printf("mult: %ld\n", select_op(MULT)(a, b));

	return 0;
}
