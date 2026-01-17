#include <stdio.h>

#define FOR(n) \
	for(int i = 0; i < (n); ++i)


#define SWAP(type, a, b) \
	type t = (a); \
	(a) = (b); \
	(b) = t;

#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define UNITE(x, y) x##y


// main
int main (void) {
	
	const char *d1 = "34.5";
	const char *d2 = "-2.0184";

	SWAP(const char *, d1, d2);

	printf("d1: %s\n", d1);
	printf("d2: %s\n", d2);

	int a = 6;
	int b = 2;
	printf("max: %d\n", MAX(a, b));

	printf("unite: %d\n", UNITE(1, 3));

	return 0;
}
