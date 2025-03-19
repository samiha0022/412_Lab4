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

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->arr[++stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1;
}

void nextGreaterElement(int arr[], int n) {
    Stack stack;
    initStack(&stack);

    int result[n];

    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        while (!isEmpty(&stack) && arr[stack.arr[stack.top]] < arr[i]) {
            result[pop(&stack)] = arr[i];
        }
        push(&stack, i);
    }

    printf("Next Greater Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    nextGreaterElement(arr, n);

    return 0;
}
