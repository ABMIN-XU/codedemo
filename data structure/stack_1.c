#include<stdio.h>
#define MAX_SIZE 100
typedef struct Stack {
    int data[MAX_SIZE];
    int top;
} stack;
void InitStack(stack *s) {
    s->top = -1;
}
int isEmpty(stack *s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}
int isFull(stack *s) {
    if (s->top == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}
int push(stack *s, int e){
    if (isFull(s)) {
        printf("栈已满，无法入栈\n");
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 1;
}
int pop(stack *s, int *e){
    if(isEmpty(s)) {
        printf("栈为空，无法出栈\n");
        return 0;
    }
    *e=s->data[s->top];
    s->top--;
    return 1;
}
int top(stack *s, int *e){
    if(isEmpty(s)) {
        printf("栈为空，无法获取栈顶元素\n");
        return 0;
    }
    *e=s->data[s->top];
    return 1;
}
int main() {
    stack s;
    InitStack(&s);
    int e;
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("栈顶元素为: ");
    top(&s, &e);
    printf("%d\n", e);
    pop(&s, &e);
    printf("出栈元素为: %d\n", e);
    printf("栈顶元素为: ");
    top(&s, &e);
    printf("%d\n", e);
    return 0;
}
