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
int insertNode_l(treenode *t,int e) {
    treenode *node=(treenode*)malloc(sizeof(treenode));
    node->data=e;
    node->left=NULL;
    node->right=NULL;
    if(t==NULL) {
        t=node;
        return 1;
    }
    t->left=node;
    return 1;
}
int insertNode_r(treenode *t,int e) {
    treenode *node=(treenode*)malloc(sizeof(treenode));
    node->data=e;
    node->left=NULL;
    node->right=NULL;
    if(t==NULL) {
        t=node;
        return 1;
    }
    t->right=node;
    return 1;
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
int main() {
    tree t;
    initTree(&t);
    insertNode_l(t.root,5);
    insertNode_r(t.root,2);
    insertNode_l(t.root->left,7);
    deleteNode(t.root);
    return 0;
}