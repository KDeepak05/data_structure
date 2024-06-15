#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct stack {
    int top;
    int arr[MAX];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (s->top < (MAX - 1)) {
        s->arr[++s->top] = item;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    } else {
        return -1;
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int evaluate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b ? a / b : 0; // Check for division by zero
        default:  return 0;
    }
}

int evaluateExpression(char* expr) {
    Stack values, ops;
    initStack(&values);
    initStack(&ops);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            push(&values, expr[i] - '0'); // Convert char to int and push
        } else if (expr[i] == '(') {
            push(&ops, expr[i]);
        } else if (expr[i] == ')') {
            while (!isEmpty(&ops) && peek(&ops) != '(') {
                int val2 = pop(&values);
                int val1 = pop(&values);
                char op = pop(&ops);
                push(&values, evaluate(val1, val2, op));
            }
            pop(&ops); // Remove '(' from stack
        } else { // Operator encountered
            while (!isEmpty(&ops) && precedence(peek(&ops)) >= precedence(expr[i])) {
                int val2 = pop(&values);
                int val1 = pop(&values);
                char op = pop(&ops);
                push(&values, evaluate(val1, val2, op));
            }
            push(&ops, expr[i]);
        }
    }

    while (!isEmpty(&ops)) { // Remaining operations
        int val2 = pop(&values);
        int val1 = pop(&values);
        char op = pop(&ops);
        push(&values, evaluate(val1, val2, op));
    }

    return pop(&values); // Final result
}

int main() {
    char expression[] = "3+2*2";
    printf("Result: %d\n", evaluateExpression(expression));
    
    return 0;
}
