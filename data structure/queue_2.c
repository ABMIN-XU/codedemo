#include<stdio.h>
typedef struct queuenode {
    int data;
    struct queuenode *next;
} queuenode;
typedef struct {
    queuenode *front;
    queuenode *rear;
} queue;
queue *initQueue() {
    queue *q=(queue*)malloc(sizeof(queue));
    queuenode *node=(queuenode*)malloc(sizeof(queuenode));
    node->data=0;
    node->next=NULL;
    q->front=node;
    q->rear=node;
    return q;
}
void enqueue(queue *q,int e) {
    queuenode *node=(queuenode*)malloc(sizeof(queuenode));
    node->data=e;
    node->next=NULL;
    q->rear->next=node;
    q->rear=node;
}
int dequeue(queue *q,int *e) {
    queuenode *node=q->front->next;
    *e=node->data;
    q->front->next=node->next;
    if(q->rear==node) {
        q->rear=q->front;
    }
    free(node);
    return 1;
}
int isEmpty(queue *q) {
    if(q->front==q->rear) {
        return 1;
    }
    return 0;
}
int getFront(queue *q) {
    if(isEmpty(q)) {
        return 0;
    }
    return q->front->next->data;
}
int main() {
    queue *q=initQueue();
    enqueue(q,5);
    enqueue(q,2);
    enqueue(q,7);
    int e;
    while(!isEmpty(q)) {
        dequeue(q,&e);
        printf("%d ",e);
    }
    return 0;
}