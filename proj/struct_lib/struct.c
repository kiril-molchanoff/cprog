#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include <stdio.h>



/************ LINKED LIST ************/


typedef struct Node {
	int x;
	struct Node *next;
} Node;


typedef struct List {
	struct Node *head;
	struct Node *tail;

	size_t len;
} List;



Node *Node_Create (
	int x
) {
	Node *node = malloc(sizeof(Node));
	node->x = x;
	return node;
}



void List_AddLast (
	List *list,
	int x
) {
	Node *node = Node_Create(x);	
	if (list->len == 0)	
		list->head = node;
	else 
		list->tail->next = node;
	list->tail = node;
	++list->len;
}
