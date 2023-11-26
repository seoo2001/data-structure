#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        addFront(l, e);
    }
    else {
        ListNode* node = (ListNode *)malloc(sizeof(ListNode));
        node->data = e;
        ListNode* p = l->H;

        for (int i = 0; i<pos-1; i++) {
            p = p->next;
        }
        node->next = p->next;
        p->next = node;
    }
}

void makeSet(ListType *l, element e) {
    if (isEmpty(l)) {
        addFront(l, e);
    } else {
        int pos = 0;
        ListNode *p = l->H;
        while (true) {
            if ((p->data) == e) return;
            if ((p->data) > e) {
                addPos(l, pos, e);
                break;
            }
            else {
                if ((p->next)==NULL) {
                    addPos(l, pos+1, e);
                    break;
                }
                pos += 1;
                p = p->next;
            }

        }
    }
}

void print(ListType *l) {
    ListNode *p = l->H;
    while (p!=NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Intersect(ListType *l1, ListType *l2) {
    ListNode* p1 = l1->H;
    ListNode* p2 = l2->H;
    int answer[20] = {0, };
    int size = 0;
    while(p1 != NULL && p2 != NULL) {
        if(p1->data > p2->data) {
            p2 = p2->next;
        } else if(p1->data < p2->data) {
            p1 = p1->next;
        } else {
            answer[size++] = p1->data;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    printf("Intersection : {");
    for(int i = 0; i < size; i++) {
        printf("%d, ", answer[i]);
    }
    printf(" }\n");
}

void Union(ListType *l1, ListType *l2) {
    ListNode* p1 = l1->H;
    ListNode* p2 = l2->H;
    int answer[20] = {0, };
    int size = 0;
    while(p1 != NULL || p2 != NULL) {
        if (p1==NULL) {
            answer[size++] = p2->data;
            p2 = p2->next;
            continue;
        }
        if (p2==NULL) {
            answer[size++] = p1->data;
            p1 = p1->next;
            continue;
        }

        if(p1->data > p2->data) {
            answer[size++] = p2->data;
            p2 = p2->next;
        } else if(p1->data < p2->data) {
            answer[size++] = p1->data;
            p1 = p1->next;
        } else {
            answer[size++] = p1->data;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    printf("Union : {");
    for(int i = 0; i < size; i++) {
        printf("%d, ", answer[i]);
    }
    printf(" }\n");
}

void Difference(ListType *l1, ListType *l2) {
    ListNode* p1 = l1->H;
    ListNode* p2 = l2->H;
    int answer[20] = {0, };
    int size = 0;
    while(p1 != NULL) {
        if (p2 == NULL) {
            answer[size++] = p1->data;
            p1 = p1->next;
            continue;
        }
        if(p1->data > p2->data) {
            p2 = p2->next;
        } else if(p1->data < p2->data) {
            answer[size++] = p1->data;
            p1 = p1->next;
        } else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    printf("Difference : {");
    for(int i = 0; i < size; i++) {
        printf("%d, ", answer[i]);
    }
    printf(" }\n");
}

int main() {
    ListType list1;
    init(&list1);
    
    ListType list2;
    init(&list2);

    srand(time(NULL));

    for(int i=0; i<10; i++) {
        makeSet(&list1, rand()%30 + 1);
        makeSet(&list2, rand()%30 + 1);
    }

    print(&list1);
    print(&list2);
    Intersect(&list1, &list2);
    Union(&list1, &list2);
    Difference(&list1, &list2);

    return 0;
}