#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>



bool is_pos (int x) { return x >= 0; }
bool is_even (int x) { return x % 2 == 0; }
bool is_prime (int x) {
	if (x < 2) 
		return false;
	for (int d = 2; d <= x / d; ++d)
		if (x % d == 0)
			return false;
	return true;
}


void arr_select (
	size_t n,
	const int a[static n],
	bool pred (int)			// -> bool (*pred) (int)
) {
	for (size_t i = 0; i < n; ++i)
		if (pred(a[i]))
			printf("%d ", a[i]);
	printf("\n");
}



// MAIN
int main (void) {

	int a[] = { -12, 3, 0, 18, 267, -34, 49, -5, 13 }; 
	const size_t n = sizeof(a) / sizeof(*a);
	
	printf("pos: ");
	arr_select(n, a, is_pos);	
	printf("even: ");
	arr_select(n, a, is_even);	
	printf("prime: ");
	arr_select(n, a, is_prime);	

	return 0;
}
