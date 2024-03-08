#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100    // Maximum size of the stack

// Creating a stack structure
struct Stack {
    int top;
    int size;
    int *arr;
};

// Function to create a stack
struct Stack *createStack(int size) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int *)malloc(size * sizeof(int));
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == stack->size - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an element to the stack
void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to print the stack
void printStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack *stack = createStack(MAX_SIZE);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    printf("Stack: ");
    printStack(stack);

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    printf("Stack: ");
    printStack(stack);

    printf("Peeked element: %d\n", peek(stack));

    return 0;
}
