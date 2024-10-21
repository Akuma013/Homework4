#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *array;    
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack){
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, int item){
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack* stack){
    if (isEmpty(stack)){
        printf("Stack underflow! Cannot pop from empty stack\n");
        return -1;
    }
    return stack->array[stack->top--];
}

void display(Stack* stack){
    if (isEmpty(stack)){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++)
        printf("%d ", stack->array[i]);
        
    printf("\n");
}

int main() {
    Stack* stack = createStack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display(stack);

    printf("Popped %d from stack\n", pop(stack));
    display(stack);

    push(stack, 40);
    push(stack, 50);
    push(stack, 60);
    push(stack, 70); // Triggering overflow
    display(stack);

    free(stack->array);
    free(stack);

    return 0;
}