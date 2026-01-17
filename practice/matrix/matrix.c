#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "matrix.h"



//-------- INTERACTION --------//


// display matrix
void Matrix_Display (const Matrix *A) {
	printf("[%zu x %zu]\n", A->m, A->n);
	for (size_t i = 0; i < A->m; ++i) {
		for (size_t j = 0; j < A->n; ++j)
			printf("%d ", A->data[i][j]);
		printf("\n");
	}
}




//-------- MATH FUNCTIONS --------//


// is matrix square
bool Matrix_IsSquare (
	const Matrix *A
) {
	return A->m == A->n;
}


// matrix determinant (recursive)
static int Matrix_Det__rec (
	const Matrix *A		
) {
	if (A->n == 1)
		return **A->data;

	int det = 0;
	for (size_t t = 0; t < A->n; ++t) {
		Matrix B = {
			.m = A->m-1, 
			.n = A->n-1 
		};
		for (size_t i = 1, m = 0; i < A->m; ++i) {
			for (size_t j = 0, n = 0; j < A->n; ++j) {
				if (j == t)
					continue;
				B.data[m][n] = A->data[i][j];
				++n;
			}
			++m;
		}
		det += (t%2 ? -1 : 1) * A->data[0][t] * Matrix_Det__rec(&B);
	}
	return det;
}


// matrix determinant
int Matrix_Det (
	const Matrix *A
) {
	if (!Matrix_IsSquare(A))
		exit(EXIT_FAILURE);
	
	return Matrix_Det__rec(A);
}


