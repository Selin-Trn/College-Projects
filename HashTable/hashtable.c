#include<stdio.h>
#include<stdlib.h>

#define SIZE 27

struct hash {
    int value, key;
};

struct hash *hashArray[SIZE];
struct hash *dummy;
struct hash *item;



int hashCode(int key) {
    return key%SIZE;
}

struct hash *search(int key) {
    int hashInd = hashCode(key);
    printf("Element searched: (%d, ?)\n", hashInd);
    while (hashArray[hashInd] != NULL) {
        if(hashArray[hashInd]->key == key) {
            printf("Element found: %d\n", hashArray[hashInd]->value);
            printf("\n");
            return hashArray[hashInd];
        }

        ++hashInd;
        hashInd %= SIZE;
    }
    printf("Element not found\n");
    printf("\n");
    return NULL;
}


void insert(int key, int value) {
    struct hash *item = (struct hash*) malloc(sizeof(struct hash));
    item->value = value;
    item->key = key;

    int hashInd = hashCode(key);
    while (hashArray[hashInd] != NULL && hashArray[hashInd]->key != -1) {
        ++hashInd;
        hashInd%=SIZE;
    }
    hashArray[hashInd] = item;
    printf("Element inserted: (%d, %d)\n", item->key, item->value);
    printf("\n");
}

struct hash *delete(struct hash* item) {
    int key = item->key;
    int hashInd = hashCode(key);
    while (hashArray[hashInd] != NULL) {
        if (hashArray[hashInd]->key == key) {
            printf("Element deleted: (%d, %d)\n", hashArray[hashInd]->key, hashArray[hashInd]->value);
            printf("\n");
            struct hash *temp = hashArray[hashInd];
            hashArray[hashInd] = dummy;
            return temp;
        }
        ++hashInd;
        hashInd %= SIZE;
    }
    printf("Element cannot be deleted (not found)\n");
    return NULL;
    printf("\n");

}

void display() {
    int i = 0;
    for (i=0 ; i<SIZE ; i++) {
        if (hashArray[i] != NULL) {
            printf("(%d, %d) ", hashArray[i]->key, hashArray[i]->value);
        }
        else {
            printf("~~ ");
        }
    }
    printf("\n\n");
}


int main() {
    dummy = (struct hash*) malloc(sizeof(struct hash));
    dummy->value = -1; 
    dummy->key = -1;

    insert(1, 685);
    insert(2, 254);
    insert(23, 464);
    display();

    item = search(23);
    delete(item);

    item = search(23);

    insert(15, 543);
    display();
    search(15);
}