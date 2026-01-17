#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


/******** GENERALIZED CONTAINER ********/

typedef enum Type {
	T_UINT32,
	T_DOUBLE,
	T_STRING
} Type;

typedef union Data {
	uint32_t ui32;
	double d;
	const char *s;
} Data;

typedef struct Value {
	Type type;
	Data data;
} Value;


// Create objects:

Value Value_UINT32(uint32_t x) {
	Value val;
	val.type = T_UINT32;
	val.data.ui32 = x;
	return val;
}
Value Value_DOUBLE(double x) {
	Value val;
	val.type = T_DOUBLE;
	val.data.d = x;
	return val;
}
Value Value_STRING(const char *x) {
	Value val;
	val.type = T_STRING;
	val.data.s = x;
	return val;
}


//---- FUNCS ----//

void Value_Display (const Value *val) {
	printf("value: ");
	switch (val->type) {
		case T_UINT32: printf("[uint32] %u\n", val->data.ui32); break;
		case T_DOUBLE: printf("[double] %lf\n", val->data.d); break;
		case T_STRING: printf("[string] %s\n", val->data.s); break;
		default: printf("(invalid type)\n");
	}
}




// M.A.I.N //

int main (void) {
	
	Value a[] = {
		Value_UINT32(4),
		Value_DOUBLE(53),
		Value_STRING("@.@"),	
		Value_DOUBLE(-0.434),
		Value_UINT32(981),
		Value_STRING("Hello, World!"),	
	};
	const size_t n = sizeof(a) / sizeof(*a);

	printf("VALUES:\n");
	for (size_t i = 0; i < n; ++i)
		Value_Display(a+i);

	return EXIT_SUCCESS;
}

