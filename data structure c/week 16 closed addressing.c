#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node** buckets;
    int size;
} HashTable;

unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

HashTable* create_table(int size) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->buckets = (Node**) calloc(table->size, sizeof(Node*));
    return table;
}

void insert(HashTable* table, int key, int value) {
    unsigned int index = hash(key);
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

int search(HashTable* table, int key) {
    unsigned int index = hash(key);
    Node* node = table->buckets[index];

    while (node) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }

    return -1; // Key not found
}

void free_table(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        Node* node = table->buckets[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

int main() {
    HashTable* table = create_table(TABLE_SIZE);

    insert(table, 1, 10);
    insert(table, 2, 20);
    insert(table, 12, 30); // Collision, handled by separate chaining

    printf("Value for key 1: %d\n", search(table, 1));
    printf("Value for key 2: %d\n", search(table, 2));
    printf("Value for key 12: %d\n", search(table, 12));
    printf("Value for key 22: %d\n", search(table, 22)); // Key not found

    free_table(table);
    return 0;
}
