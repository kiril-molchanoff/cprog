#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


/******** USEFUL MACROS ********/


#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#define TOSTRING(x) #x
#define CONCAT(a, b) a##b

#define ARR_LEN(arr) (sizeof(arr) / sizeof(*(arr)))
#define SWAP(a, b) { \
	unsigned long long a_sz = sizeof(a); \
	unsigned long long b_sz = sizeof(b); \
	if (a_sz == b_sz) { \
		unsigned char buff[a_sz]; \
		memcpy(&(a), &(b), a_sz); \
		memcpy(&(b), buff, a_sz); \
	} \
}


#define SAFE_FREE(p) { \
	free(p); \
	(p) = NULL; \
}


#define OFFSET(T, field) ((size_t)&((T *)0)->field)




/******** MAIN ********/


// err handler
int err (const char *mes) {
	fprintf(stderr, "<ERROR>: %s\n", mes);
	return EXIT_FAILURE; 
}


// main
int main (void) {
	

	return EXIT_SUCCESS;
}

