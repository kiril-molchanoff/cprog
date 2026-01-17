#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>




/******** JAGGED ARRAY ********/


//---- STRUCT ----//


struct JaggedArr {
	size_t n;		// rows
	size_t *m;		// cols
	int **A;		// jagged arr
};



//---- METHODS ----//

// Free
void JaggedArr_Free (
	struct JaggedArr *arr
) {
	for (size_t i = 0; i < arr->n; ++i) {
		free(arr->A[i]);
		arr->A[i] = NULL;
	}
	free(arr->A);
	arr->A = NULL;
	free(arr->m);
	arr->m = NULL;
}

// Allocate
bool JaggedArr_Alloc (
	struct JaggedArr *arr
) {
	arr->A = calloc(arr->n, sizeof(*arr->A));
	if (arr->A == NULL)
		return false;

	for (size_t i = 0; i < arr->n; ++i) {
		arr->A[i] = calloc(arr->m[i], sizeof(**arr->A));
		if (arr->A[i] == NULL) {
			JaggedArr_Free(arr);
			return false;
		}
	}
	return true;
}

// Create
bool JaggedArr_Init ( 
	size_t n,
	size_t m[static n],
	struct JaggedArr *arr
) {
	// alloc & init size
	arr->n = n;
	arr->m = calloc(n, sizeof(size_t));
	if (arr->m == NULL)
		return false;

	for (size_t i = 0; i < n; ++i)
		arr->m[i] = m[i];

	// alloc array
	return JaggedArr_Alloc(arr);
}

// Display
void JaggedArr_Display ( 
	const struct JaggedArr *arr
) {
	for (size_t i = 0; i < arr->n; ++i) {
		for (size_t j = 0; j < arr->m[i]; ++j)
			printf("%10d ", arr->A[i][j]);
		printf("\n");
	}
}

// Set 
void JaggedArr_Set ( 
	struct JaggedArr *arr
){
	for (size_t i = 0; i < arr->n; ++i)
		for (size_t j = 0; j < arr->m[i]; ++j)
			arr->A[i][j] = rand();
}




/******** MAIN ********/


// err handler
int err (const char *mes) {
	fprintf(stderr, "<ERROR>: %s\n", mes);
	return EXIT_FAILURE; 
}


// main
int main (void) {
	
	srand((unsigned)time(NULL));
	

	struct JaggedArr arr;
	if (!JaggedArr_Init(5, (size_t[]){4,2,5,4,3}, &arr))
		return err("Allocation failure");

	JaggedArr_Set(&arr);
	JaggedArr_Display(&arr);

	JaggedArr_Free(&arr);

	return EXIT_SUCCESS;
}

