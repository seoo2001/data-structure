#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

typedef struct ListType {
	ListNode *tail;
	int size;
} ListType;

void init(ListType *L) {
	L->tail = NULL;
	L->size = 0;
}

int isEmpty(ListType *L) {
	return L->size == 0;
}

void insertLast(ListType *L, element e) {
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	if (isEmpty(L)) {
		L->tail = node;
		node->link = node;
	} else {
		node->link = L->tail->link;
		L->tail->link = node;
		L->tail = node;
	}
	L->size++;
}

void insertFirst(ListType *L, element e) {
	if (isEmpty(L)) {
		insertLast(L, e);
	} else {
		ListNode *node = (ListNode*)malloc(sizeof(ListNode));
		node->data = e;
		node->link = L->tail->link;
		L->tail->link = node;
		L->size++;
	}
}

void print(ListType *L) {
	printf("%d ", L->size);
	if(isEmpty(L)) {
		return;
	}
	ListNode *p = L->tail->link;
	for(int i=0; i<L->size; i++) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

void print2(ListType *L) {
	printf("%d ", L->size);
	if(isEmpty(L)) {
		return;
	}
	ListNode *p = L->tail->link;
	while(true) {
		printf("%d ", p->data);
		
		if (p==L->tail) break;
		
		p=p->link;
	}
	printf("\n");
}

element deleteFirst(ListType *L) {
	if (isEmpty(L)) {
		return -1;
	}
	ListNode *p = L->tail;
	ListNode *q = L->tail->link;
	p->link = q->link;
	if(p==q) L->tail = NULL;
	L->size--;
	element e = q->data;
	free(q);
	return e;
}

element deleteLast(ListType *L) {
	if (isEmpty(L)) {
		return -1;
	}
	ListNode *p = L->tail;
	ListNode *q = L->tail->link;
	element e = p->data;
	
	if(p==q) L->tail = NULL;
	else {
		while (q->link != L->tail) {
			q = q->link;
		}
		L->tail = q;
		q->link = p->link;
	}
	L->size--;
	free(p);
	return e;
}


int main() {
	ListType L;
	init(&L);
	insertLast(&L, 10); print(&L);
	insertFirst(&L, 20); print(&L);
	insertFirst(&L, 30); print(&L);
	insertFirst(&L, 40); print(&L);
	insertLast(&L, 50); print(&L);
	insertLast(&L, 60); print2(&L);
	deleteFirst(&L); print2(&L);
	deleteLast(&L); print2(&L);
	deleteLast(&L); print2(&L);
	deleteLast(&L); print2(&L);
	insertLast(&L, 50); print(&L);
	insertLast(&L, 60); print2(&L);
	return 0;
}











