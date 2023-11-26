
#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef char element;

typedef struct ListNode {
	element data;
	struct ListNode *next;
} ListNode;

typedef struct ListType {
	ListNode *head;
	int size;
} ListType;

void init(ListType *L) {
	L->head = NULL;
	L->size = 0;
}

int isEmpty(ListType *L) {
	return L->size==0;
}

void insertFirst(ListType *L, element e) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = e;
	node->next = L->head;
	L->head = node;
	L->size++;
}

void insertLast(ListType *L, element e) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = e;
	node->next = NULL;
	ListNode *p = L->head;
	L->size++;
	if (not p) {
		L->head = node;
		return;
	}
	while (p->next) {
		p = p->next;
	}
	p->next = node;
}

// 1 e 2 e 3 e ... (insert pos)
void insertPos(ListType *L, int pos, element e) { 
	if (pos==1) {
		insertFirst(L, e);
	} else if (pos==L->size+1) {
		insertLast(L, e);
	} else {
		ListNode *node = (ListNode *)malloc(sizeof(ListNode));
		ListNode *p = L->head;
		for(int i=0; i<pos-2; i++) {
			p=p->next;
		}
		node->data = e;
		node->next = p->next;
		p->next = node;
		L->size++;
	}
}

element deleteFirst(ListType *L) {
	ListNode *p = L->head;
	element e = p->data;
	L->head = p->next;
	free(p);
	L->size--;
	return e;
}

element deletePos(ListType *L, int pos) {
	if (pos==1) {
		return deleteFirst(L);
	}
	ListNode *p = L->head;
	for(int i=0; i<pos-2; i++) {
		p = p->next;	
	}
	ListNode *p0 = p->next;
	element e = p0->data;
	p->next = p0->next;
	free(p0);
	L->size--;
	return e;
}

void print(ListType *L) {
	for(ListNode *p = L->head; p!=NULL; p=p->next) {
		printf("%c ", p->data);
	}
	printf("\n");
}

int main() {
	ListType L;
	init(&L);
	insertLast(&L, 'C'); print(&L);
	insertFirst(&L, 'A'); print(&L);
	insertFirst(&L, 'B'); print(&L);
	insertPos(&L,2,'F'); print(&L);
	insertLast(&L, 'C'); print(&L);
	deletePos(&L, 3); print(&L);
	
	return 0;
}
