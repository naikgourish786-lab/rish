 	      #include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 5
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;
void initStack(Stack *s) {
    s->top = -1;
}
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}
bool isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->data[++(s->top)] = value;
    printf("Pushed: %d\n", value);
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop\n");
        return -1;
    }
    return s->data[(s->top)--];
}
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->data[s->top];
}
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
int main() {
    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    printf("Top element (peek): %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    display(&s);
    return 0;
}
