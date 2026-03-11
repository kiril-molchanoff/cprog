#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include "struct.c"


int main (void) {

	List list = {0};

	size_t n = 3;
	for (size_t i = 1; i <= n; ++i)
		List_AddLast(&list, (int)i);

	
	printf("head [%d]\n", list.head->x);
	printf("tail [%d]\n", list.tail->x);
	

	for (Node *node = list.head; node != NULL; node = node->next)
		printf("[%d] -> ", node->x);
	printf("\n");


	return EXIT_SUCCESS;	
}
