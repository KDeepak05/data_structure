#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10
#define LOAD_FACTOR_THRESHOLD 0.7

typedef struct {
    int key;
    int value;
    int is_occupied;
} HashItem;

typedef struct {
    HashItem* items;
    int size;
    int count;
} HashTable;

unsigned int hash(int key, int size) {
    return key % size;
}

HashTable* create_table(int size) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (HashItem*) calloc(table->size, sizeof(HashItem));
    return table;
}

void rehash(HashTable* table);

void insert(HashTable* table, int key, int value) {
    if ((float) table->count / table->size >= LOAD_FACTOR_THRESHOLD) {
        rehash(table);
    }

    unsigned int index = hash(key, table->size);

    while (table->items[index].is_occupied) {
        index = (index + 1) % table->size;
    }

    table->items[index].key = key;
    table->items[index].value = value;
    table->items[index].is_occupied = 1;
    table->count++;
}

int search(HashTable* table, int key) {
    unsigned int index = hash(key, table->size);

    while (table->items[index].is_occupied) {
        if (table->items[index].key == key) {
            return table->items[index].value;
        }
        index = (index + 1) % table->size;
    }

    return -1; // Key not found
}

void rehash(HashTable* table) {
    int old_size = table->size;
    HashItem* old_items = table->items;

    table->size *= 2;
    table->count = 0;
    table->items = (HashItem*) calloc(table->size, sizeof(HashItem));

    for (int i = 0; i < old_size; i++) {
        if (old_items[i].is_occupied) {
            insert(table, old_items[i].key, old_items[i].value);
        }
    }

    free(old_items);
}

void free_table(HashTable* table) {
    free(table->items);
    free(table);
}

int main() {
    HashTable* table = create_table(INITIAL_SIZE);

    insert(table, 1, 10);
    insert(table, 2, 20);
    insert(table, 12, 30); // Collision, handled by linear probing

    printf("Value for key 1: %d\n", search(table, 1));
    printf("Value for key 2: %d\n", search(table, 2));
    printf("Value for key 12: %d\n", search(table, 12));
    printf("Value for key 22: %d\n", search(table, 22)); // Key not found

    free_table(table);
    return 0;
}
