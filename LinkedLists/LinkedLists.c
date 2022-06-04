#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

//FUNCTIONS

struct node *new_node(int val) {
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}


struct node *new_LL() {
    struct node *head = NULL;
    struct node *body = NULL;
    struct node *tail = NULL;

    head = malloc(sizeof(struct node));
    body = malloc(sizeof(struct node));
    tail = malloc(sizeof(struct node));

    head->data = 1;
    head->next = body;

    body->data = 2;
    body->next = tail;

    tail->data = 3;
    tail->next = NULL;

    return head;
}


struct node *new_LL2(int a, int b, int c) {
    struct node *head = NULL;
    struct node *body = NULL;
    struct node *tail = NULL;
    
    head = new_node(a);
    body = new_node(b);
    tail = new_node(c);
    
    head->next = body;
    body->next = tail;
    return head;
}


void print_LL(struct node *head) {
struct node *current;
current = head;
    for (; current != NULL; current = current->next) {
        printf("%d -> ", current->data);
    }
    puts("NULL\n");
}


void push_to_head(struct node **head, int x) {
    printf("\nAdding to the head\n");
    struct node *new_head = NULL;
    new_head = new_node(x);
    new_head->next = *head;
    *head = new_head;
}


void push(struct node **head, int x) {
    printf("\nAdding to the end\n");
    struct node *new_tail = NULL;
    new_tail = new_node(x);
    struct node *temp = *head;

    if (temp == NULL) {
        *head = new_tail;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_tail;
    }
}

void pop_head(struct node **head) {
    printf("\nDeleting from the head\n");
    struct node *temp = *head;
    *head = (*head)->next;

    if (temp !=NULL) {	
        free(temp);
    }
}


void pop(struct node **head) {
    printf("\nDeleting from the tail\n");
    struct node *current = *head;
    struct node *aftrCur = NULL;

    if (*head != NULL) {
        while (current->next != NULL) {
            aftrCur = current;
            current = current->next;
        }
        if (current != NULL) {
            free(current);
            aftrCur->next = NULL;
        }
    }
    else {
        printf("List empty\n");
    }
}


struct node *search_node(struct node *head, int val) {
    struct node *temp;
    temp = head;
    while (temp->data != val) {
        printf("Value searched: %d. Current node value: %d. \n", val, temp->data);
        temp = temp->next;
    }
    if (temp->data == val) {
        printf("Node found %d. \n", val);
        return temp;
    }
    else {
        printf("Node not found");
    }
}

int len_LL(struct node *head) {
    struct node *temp;
    temp = head;
    int counter = 0;
    while(temp){
        temp = temp->next;
        counter++;
      }
    printf("Linked list length: %d\n", counter);
    return counter;
}


void traverse_LL(struct node *head) {
    struct node *temp;
    temp = head;
    
    if(temp != NULL) {
        while (temp->next != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> NULL\n", temp->data);
    }
}

int main() {
    struct node *linkie = new_LL2(1,2,3);
    traverse_LL(linkie);
    print_LL(linkie);
    len_LL(linkie);


    push_to_head(&linkie, 0);
    push(&linkie, 4);
    print_LL(linkie);
    len_LL(linkie);

    pop_head(&linkie);
    print_LL(linkie);
    len_LL(linkie);

    pop(&linkie);
    print_LL(linkie);
    len_LL(linkie);

    search_node(linkie, 2);
    
   	return 0;
}