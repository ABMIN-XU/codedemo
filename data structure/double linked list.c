#include <stdio.h>
#include <stdlib.h>
typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode, *DList;

DList InitDList() {
    DNode *head = (DNode*)malloc(sizeof(DNode));
    if (head == NULL) {
        perror("malloc head failed");
        exit(EXIT_FAILURE);
    }
    head->prev = NULL;
    head->next = NULL;
    return head;
}

DNode* CreateNode(int val) {
    DNode *newNode = (DNode*)malloc(sizeof(DNode));
    if (newNode == NULL) {
        perror("malloc new node failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void ListPushBack(DList head, int val) {
    if (head == NULL) return;

    DNode *newNode = CreateNode(val);
    DNode *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->prev = cur;
}

void ListPushFront(DList head, int val) {
    if (head == NULL) return;

    DNode *newNode = CreateNode(val);
    newNode->next = head->next;
    if (head->next != NULL) {
        head->next->prev = newNode;
    }
    head->next = newNode;
    newNode->prev = head;
}

void ListPrintForward(DList head) {
    if (head == NULL || head->next == NULL) {
        printf("链表为空\n");
        return;
    }

    DNode *cur = head->next;
    printf("正向遍历: ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void ListPrintBackward(DList head) {
    if (head == NULL || head->next == NULL) {
        printf("链表为空\n");
        return;
    }

    DNode *cur = head->next;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    printf("反向遍历: ");
    while (cur != head) {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}

void ListRemove(DList head, int val) {
    if (head == NULL || head->next == NULL) return;

    DNode *cur = head->next;
    while (cur != NULL) {
        if (cur->data == val) {
            cur->prev->next = cur->next;
            if (cur->next != NULL) {
                cur->next->prev = cur->prev;
            }
            free(cur);
            return;
        }
        cur = cur->next;
    }
    printf("未找到值为 %d 的节点\n", val);
}

void ListDestroy(DList head) {
    if (head == NULL) return;

    DNode *cur = head;
    while (cur != NULL) {
        DNode *next = cur->next;
        free(cur);
        cur = next;
    }
}

int main() {
    DList list = InitDList();

    ListPushBack(list, 10);
    ListPushBack(list, 20);
    ListPushBack(list, 30);
    printf("=== 尾插 10、20、30 后 ===\n");
    ListPrintForward(list);
    ListPrintBackward(list);

    ListPushFront(list, 5);
    ListPushFront(list, 1);
    printf("\n=== 头插 5、1 后 ===\n");
    ListPrintForward(list);
    ListPrintBackward(list);

    ListRemove(list, 20);
    printf("\n=== 删除值为20的节点后 ===\n");
    ListPrintForward(list);
    ListPrintBackward(list);

   

    ListDestroy(list);
    list = NULL;
    

    return 0;
}
