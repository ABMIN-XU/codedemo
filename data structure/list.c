#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node* initlist(){
    node *head=(node*)malloc(sizeof(node));
    head->next=NULL;
    head->data=0;
    return head;
}
void insert1(node*l,int e){
    node *p=(node*)malloc(sizeof(node));
    p->data=e;
    p->next=l->next;
    l->next=p;
}
void listnode(node* l){
    node *p=l->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
node* get_tail(node*l){
    node *p=l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
node* insert2(node*l,int e){
    node *p=(node*)malloc(sizeof(node));
    p->data=e;
    p->next=l->next;
    l->next=p;
    return p;
}
node* revese(node*l){
    node *first=NULL;
    node *second=l->next;
    while(second!=NULL){
        node* third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    node *p=initlist();
    p->next=first;
    return p;
}
int main(){
    node *l=initlist();
    node *tail=get_tail(l);
    tail=insert2(tail,1);
    tail=insert2(tail,2);
    tail=insert2(tail,3);
    listnode(l);
    node *p=revese(l);
    listnode(p);
    return 0;
}