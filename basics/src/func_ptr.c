#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>



/******** OPERATIONS ********/


// pseudonym "int (int,int)" -> op_f
typedef int64_t op_f(int64_t a, int64_t b);



op_f add;
op_f sub;
op_f mult;


// add
int64_t add (int64_t a, int64_t b) {
	int64_t res = a + b;
	printf("add: %ld + %ld = %ld\n", a, b, res);
	return res;
}

// subtract
int64_t sub (int64_t a, int64_t b) {
	int64_t res = a - b;
	printf("sub: %ld - %ld = %ld\n", a, b, res);
	return res;
}

// multiply
int64_t mult (int64_t a, int64_t b) {
	int64_t res = a * b;
	printf("mult: %ld * %ld = %ld\n", a, b, res);
	return res;
}




/******** HELPERS ********/


// initialize ops
void init_ops (
	size_t n, 			// array len
	op_f *ops[static n]	// array of operations (min n)
) {

	for (size_t i = 0; i < n; ++i)
		switch (i % 3) {
			case 0: 
				ops[i] = add; 
				break;
			case 1:
				ops[i] = sub;
				break;
			case 2:
				ops[i] = mult;
				break;
		}
}

// invoke ops
void invoke_ops (
	size_t n,					// array len
	op_f *const ops[static n],	// array of operations (min n)
	int64_t a, int64_t b
) {

	for (size_t i = 0; i < n; ++i)
		ops[i](a, b);
}



// MAIN
int main (void) {

	const size_t n = 1<<4;
	op_f *ops[n];  // arr[n] of ptr to func op_f: "int (int,int)"

	init_ops(n, ops);
	printf("invoke:\n");
	invoke_ops(n, ops, 4, 7);

	return 0;
}
