#include<stdio.h>
#include<stdlib.h>
typedef struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
} treenode;
typedef struct {
    treenode *root;
} tree;
void initTree(tree *t) {
    t->root=NULL;
}
treenode *insertNode(treenode *t,int e) {
    treenode *node=(treenode*)malloc(sizeof(treenode));
    node->data=e;
    node->left=NULL;
    node->right=NULL;
    if(t==NULL) {
        t=node;
        return node;
    }
    else {
        if(t->left==NULL) {
            t->left=node;
            return node;
        }
        else if(t->right==NULL) {
            t->right=node;
            return node;
        }
    }
    free(node);
    return NULL;
}
int deleteNode(treenode *t) {
    if(t==NULL) {
        return 0;
    }
    deleteNode(t->left);
    deleteNode(t->right);
    free(t);
    return 1;
}
void printTree(treenode *t) {
    if(t==NULL) {
        return;
    }
    printf("%d ",t->data);
    printTree(t->left);
    printTree(t->right);
}
int main() {
    tree t;
    initTree(&t);
    t.root = insertNode(t.root,5);
    insertNode(t.root,2);
    insertNode(t.root,7);
    printTree(t.root);
    deleteNode(t.root);
    return 0;
}