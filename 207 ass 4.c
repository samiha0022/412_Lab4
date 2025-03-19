#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = value;
    } else {
        printf("Stack Overflow! Cannot push %d.\n", value);
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    printf("Stack Underflow! Cannot pop.\n");
    return -1;
}

int findMiddle(Stack* stack) {
    Stack tempStack;
    initStack(&tempStack);

    int midIndex = (stack->top + 1) / 2;
    int middleElement;

    for (int i = 0; i <= midIndex; i++) {
        if (i == midIndex) {
            middleElement = pop(stack);
        } else {
            push(&tempStack, pop(stack));
        }
    }

    while (!isEmpty(&tempStack)) {
        push(stack, pop(&tempStack));
    }

    return middleElement;
}

int main() {
    Stack stack;
    initStack(&stack);

    int n, value;

    printf("Enter number of elements to push onto the stack: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }

    int middleElement = findMiddle(&stack);

    printf("Middle Element: %d\n", middleElement);

    return 0;
}
