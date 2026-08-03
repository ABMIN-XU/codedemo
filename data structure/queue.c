#include<stdio.h>
#define MAX_SIZE 100
typedef struct queue {
    int data[MAX_SIZE];
    int front;
    int rear;
} queue;
void initQueue(queue *q) {
    q->front=0;
    q->rear=0;
}
int isEmpty(queue *q) {
    if(q->front==q->rear) {
        return 1;
    }
    return 0;
}
int dequeue(queue *q) {
    if(isEmpty(q)) {
        return 0;
    }
    int e=q->data[q->front];
    q->front++;
    return e;
}
int queuefull(queue *q) {
    if(q->front>0){
        int step=q->front;
    for(int i=q->front;i<q->rear;i++) {
        q->data[i-step]=q->data[i];
    }
    q->front=0;
    q->rear=q->rear-step;
    return 1;
    }
    else {
        return 0;
    }
}
int enqueue_1(queue *q,int e) {
    if(q->rear==MAX_SIZE) {
        if(queuefull(q)) {
            q->data[q->rear]=e;
            q->rear++;
            return 1;
        }
        else {
            return 0;
        }
    }
    q->data[q->rear]=e;
    q->rear++;
    return 1;
}
int enqueue_2(queue *q,int e) {
    if((q->rear+1)%MAX_SIZE==q->front) {
        return 0;
    }
    q->data[q->rear]=e;
    q->rear=(q->rear+1)%MAX_SIZE;
    return 1;
}
int main() {
    queue q;
    initQueue(&q);
    enqueue(&q,3);
    enqueue(&q,5);
    enqueue(&q,7);
    while (!isEmpty)
    {
        printf("%d\n",dequeue(&q));
    }
    return 0;
}