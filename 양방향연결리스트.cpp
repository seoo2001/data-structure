#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode *prev, *next;
} ListNode;

typedef struct DListType {
	ListNode *tail, *head;
	int size;
} ListType;

void init(ListType *DL) {
	DL->tail = NULL;
	DL->head = NULL;
	DL->size = 0;
}

int isEmpty(DListType *DL) {
	return DL->size == 0;
}

void insertFirst(DListType *DL, element e) {
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	DListNode *p = DL->head;
	node->data = e;
	node->prev = NULL;
	node->next = p;
	
	if (isEmpty(DL)) {
		DL->head = DL->tail = node;
	} else {
		DL->head = node;
		p->prev = node;
	}
	DL->size++;
}

void insertLast(DListType *DL, element e) {
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	DListNode *p = DL->tail;
	node->data = e;
	node->next = NULL;
	node->prev = p;
	
	if (isEmpty(DL)) {
		DL->head = DL->tail = node;
	} else {
		DL->tail = node;
		p->next = node;
	}
	DL->size++;
}

void insert(DListType* DL, int pos, element e) {
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	DListNode *p = DL->head;
	node->data = e;
	if (pos==1) insertFirst(DL, e);
	else if (pos==DL->size+1) insertLast(DL, e);
	else {
		for (int i = 1; i< pos; i++) {
			p = p->next;
		}
		node->prev = p->prev;
		node->next = p;
		
		p->prev->next = node;
		p->prev = node;
	}
}

void print(DListType *DL) {
	for(DListNode *p = DL->head; p != NULL; p = p->next) {
		printf("%d ", p->data);
	}
	printf("\n");
}



int main() {
	DListType DL;
	init(&DL);
	insertLast(&DL, 10); print(&DL);
	insertFirst(&DL, 20); print(&DL);
	insertFirst(&DL, 30); print(&DL);
	insertLast(&DL, 40); print(&DL);
	insert(&DL, 2, 11); print(&DL);
	insert(&DL, 4, 22); print(&DL);
	return 0;
}





