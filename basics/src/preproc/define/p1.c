#include <stdio.h>

#define BEGIN {
#define END }


#define MAX_CNT 1<<3
#define ADD(x,y) (x+y)


// main
int main (void)
BEGIN
	
	int a[MAX_CNT] = { 11, 12, 13, 14 };
	
	for (size_t i = 0; i < MAX_CNT; ++i)
		printf("%d, ", ADD(a[i], 10));
	printf("\n");
	
	return 0;
END
