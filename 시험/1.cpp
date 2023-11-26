#include <stdio.h>
#include <stdlib.h>


typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *next;
} ListNode;

typedef struct ListType {
    ListNode *H;
} ListType;

void init(ListType *l) {
    l->H = NULL;
}

int isEmpty(ListType *l) {
    return l->H==NULL;
}

void addFront(ListType *l, element e) {
    ListNode* node = (ListNode *)malloc(sizeof(ListNode));
    node->data = e;
    node->next = l->H;
    l->H = node;
}

void addPos(ListType *l, int pos, element e) {
    if (pos==0) {
        addFront(l, element e);
    } else {
        ListNode* node = (ListNode *)malloc(sizeof(ListNode));
    }
}


int main() {
    ListType list1;
    init(&list1);
    



    return 0;
}