#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>



typedef struct {
	size_t x;
	size_t y;
	size_t z;
} size3d_t;



void get_arr3d (
	// params 
	size3d_t size,
	const int16_t A[static size.x][size.y][size.z]) {

	for (size_t i = 0; i < size.x; ++i) {
		for (size_t j = 0; j < size.y; ++j) {
			for (size_t k = 0; k < size.z; ++k)
				printf("%hd ", A[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}
}


void set_arr3d ( 
	// params
	size3d_t size,
	int16_t A[static size.x][size.y][size.z]) {

	for (size_t i = 0; i < size.x; ++i)
		for (size_t j = 0; j < size.y; ++j)
			for (size_t k = 0; k < size.z; ++k)
				A[i][j][k] = i*size.y*size.z + j*size.z + k;
}



// main:
int main (void) {

	const size_t x = 3;
	const size_t y = 2;
	const size_t z = 4;

	int16_t A[x][y][z];
	size3d_t size = {x,y,z};

	set_arr3d((size3d_t){x,y,z}, A);
	get_arr3d((size3d_t){x,y,z}, (const int16_t (*)[y][z])A);

	return 0;
}
