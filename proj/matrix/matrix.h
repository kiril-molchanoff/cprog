#ifndef MATRIX_H
#define MATRIX_H


#define MATRIX_MAX_SIZE 100

typedef struct Matrix {
	size_t m;
	size_t n;
	int data[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE];
} Matrix;



void Matrix_Display	(const Matrix *);
bool Matrix_IsSquare (const Matrix *);
int Matrix_Det (const Matrix *);


#endif

