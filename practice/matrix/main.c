#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "matrix.h"




// ERROR HANDLING //

enum ERR {
	ERR_OK,
	ERR_INV_INPUT
};

int err (enum ERR type) {
	const char *mes;
	switch (type) {
		case ERR_INV_INPUT:
			mes = "Invalid input";
			break;
		default:
			mes = "Unindentified error";
			break;
	}
	if (type != ERR_OK)
		printf("ERROR: %s\n", mes);
	return type;
}



// M.A.I.N //

int main (void) {

	Matrix A = {0};
	
	size_t n;
	scanf("%zu", &n);
	A.m = A.n = n;

	for (size_t i = 0; i < A.m; ++i)
		for (size_t j = 0; j < A.n; ++j)
			scanf("%d", &A.data[i][j]);


	Matrix_Display(&A);
	printf("det A = %d\n", Matrix_Det(&A));

	return err(ERR_OK);
}
