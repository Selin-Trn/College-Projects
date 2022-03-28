#include <stdio.h>
#include <stdlib.h>

/******************************************************************************************************************/
struct Node {
	int data;
	struct Node* next;
};


typedef struct Node* node;		// made defining node struct less wordy


node newNode(int value) {		// function to create a node
	node new = malloc(sizeof(node));
	new->data = value;
	new->next = NULL;
	return new;
}
/******************************************************************************************************************/
struct linkedList {
	node head;
	node body;
	node tail;
};

typedef struct linkedList* linList;

/*** ADDING A NODE ***/
linList push(linList lin_list, int value) {		// pushes a new node to the beginning of the list
	node new_node = newNode(value);

	if (lin_list->head == NULL) {		// empty list
		lin_list->head = new_node;
	};

	new_node->next = lin_list->head;
	lin_list->head = new_node;

	return lin_list;
}


void insertAfter(node prev_node, int value) {	// insert a new node
	if (prev_node == NULL) {
		printf("Previous_node must point to another node!");
		return;
	}
	node new_node = newNode(value);
	new_node->data = value;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(node tail_node, int value) { // append a node at the end of the list
	node new_node = newNode(value);
	new_node->next = NULL;

	if (tail_node->next == NULL) {
		tail_node->next = new_node;
	}

	while (tail_node->next != NULL) {
		tail_node = tail_node->next;
		tail_node->next = new_node;
	}
}

/*** REMOVING A NODE ***/
/*linList remove(linList lin_list) {		// removing a node from the end of the list
	if (lin_list->tail == NULL) {
		return lin_list;
	}

	node index = lin_list->head;

	while(index->next != lin_list->tail) {
		index = index->next;
	}

	lin_list->tail = index;
	index->next = NULL;
	return lin_list;
}
*/
/*** TRAVERSING A LINKED LIST ***/
void printList(linList lin_list) {
	node index = lin_list->head;
	while (index != NULL) {
		printf("%d ", index->data);
		index = index->next;
	}
}

/*** SIZE OF A LINKED LIST ***/
int sizeList(linList lin_list) {
	int size = 0;
	node index = lin_list->head;
	while (index != NULL) {
		size++;
		index = index->next;
	}
	printf("Size of the list is: %d ", size);
	return size;
}

int main() {
	linList new_list = malloc(sizeof(linList));
	push(new_list, 3);
	push(new_list, 2);
	push(new_list, 1);

	printList(new_list);
}