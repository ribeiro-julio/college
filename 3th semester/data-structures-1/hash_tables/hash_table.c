#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 17


typedef struct {
    int x;
    char info[100];
} HashItem;

typedef struct {
    HashItem *array[MAX_SIZE];
    int size;
} HashArray;


void destroy(HashArray *table) {
    for(int i = 0; i < MAX_SIZE; i++)
        table->array[i] = NULL;
    
    table->size = 0;
}

int linearProbing(int pos) {
    return (pos+1) % MAX_SIZE;
}

int hashFunction(int x) {
    return x % MAX_SIZE;
}

void init(HashArray *table) {
    for(int i = 0; i < MAX_SIZE; i++)
        table->array[i] = NULL;
    
    table->size = 0;
}

bool isEmpty(HashArray *table) {
    return table->size == 0;
}

bool isFull(HashArray *table) {
    return table->size == MAX_SIZE;
}

int tableSize(HashArray *table) {
    return table->size;
}

bool insert(HashArray *table, HashItem *item) {
    if(isFull(table)) {
        printf("Insertion error -> Table is full\n");
        return false;
    }

    int pos = hashFunction(item->x);

    while(true) {
        if(pos >= MAX_SIZE) {
            printf("Insertion error -> No space left in the table\n");
            return false;
        }

        if(table->array[pos] != NULL)
            pos = linearProbing(pos);
        else {
            table->array[pos] = item;
            table->size++;
            return true;
        }
    }
}

bool removeItem(HashArray *table, int x) {      // TODO
    if(isEmpty(table)) {
        printf("Removal error -> Table is empty\n");
        return false;
    }

    int pos = hashFunction(x);

    if(table->array[pos] == NULL) {
        printf("Removal error -> Key not found\n");
        return false;
    }

    table->array[pos] = NULL;
    table->size--;
    return true;
}

bool search(HashArray *table, int x) {      // TODO
    if(isEmpty(table)) {
        printf("Search error -> Table is empty\n");
        return false;
    }

    int pos = hashFunction(x);

    if(table->array[pos] == NULL) {
        printf("Search warning -> Key not found\n");
        return false;
    }
    
    return table->array[pos]->x == x;
}

void printTable(HashArray *table) {
    printf("-------------------------------------------\n");
    printf("               Table Content\n");
    printf("-------------------------------------------\n");
    for(int i = 0; i < MAX_SIZE; i++) {
        if(table->array[i] != NULL)
            printf("  [%d](%d, %s)\n", i, table->array[i]->x, table->array[i]->info);
        else
            printf("  [%d](Empty)\n", i);
    }
    printf("-------------------------------------------\n");
}


int main() {
    HashArray hashTable;

    init(&hashTable);

    HashItem a = {1, "A"};
    HashItem g = {7, "G"};
    HashItem u = {21, "U"};
    HashItem d = {4, "D"};
    HashItem e = {5, "E"};
    HashItem s = {19, "S"};
    HashItem l = {12, "L"};
    HashItem i = {9, "I"};
    HashItem c = {3, "C"};
    HashItem h = {8, "H"};

    insert(&hashTable, &a);
    insert(&hashTable, &g);
    insert(&hashTable, &u);
    insert(&hashTable, &a);
    insert(&hashTable, &d);
    insert(&hashTable, &e);
    insert(&hashTable, &s);
    insert(&hashTable, &a);
    insert(&hashTable, &l);
    insert(&hashTable, &s);
    insert(&hashTable, &i);
    insert(&hashTable, &c);
    insert(&hashTable, &h);
    insert(&hashTable, &a);

    printTable(&hashTable);

    return 0;
}