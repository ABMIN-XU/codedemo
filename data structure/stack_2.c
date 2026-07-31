#include<stdio.h>
typedef struct stack {
    int data;
    struct stack *next;
} stack;
stack* InitStack() {
    stack *s = (stack*)malloc(sizeof(stack));
    s->data = 0;
    s->next = NULL;
    return s;
}
int isEmpty(stack *s) {
    if (s->next == NULL) {
        return 1;
    }
    return 0;
}
int push(stack *s, int e){
    stack *p=(stack*)malloc(sizeof(stack));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return 1;
}
int pop(stack *s, int *e){
    if(isEmpty(s)) {
        printf("栈为空，无法出栈\n");
        return 0;
    }
    stack *p=s->next;
    *e=p->data;
    s->next=p->next;
    free(p);
    return 1;
}
int top(stack *s, int *e){
    if(isEmpty(s)) {
        printf("栈为空，无法获取栈顶元素\n");
        return 0;
    }
    *e=s->next->data;
    return 1;
}
int main() {
    stack *s = InitStack();
    int e;
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printf("栈顶元素为: ");
    top(s, &e);
    printf("%d\n", e);
    pop(s, &e);
    printf("出栈元素为: %d\n", e);
    printf("栈顶元素为: ");
    top(s, &e);
    printf("%d\n", e);
    return 0;
}
