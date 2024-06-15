#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return; // Check for malloc failure

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    
    Node* temp = q->front;
    int data = temp->data;
    
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL; // If the queue is empty after dequeue, reset rear to NULL
    }
    
    free(temp);
    
    return data;
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    
    printf("Dequeued: %d\n", dequeue(&q));
    
    enqueue(&q, 30);
    
    printf("Dequeued: %d\n", dequeue(&q));
    
    return 0;
}
