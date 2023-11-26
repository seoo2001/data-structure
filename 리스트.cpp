#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef int element;

typedef struct ListType {
	element data[N];
	int size;
} ListType;

void init(ListType *L) {
	L->size = 0;
}

int isEmpty(ListType *L) {
	return L->size==0;
}

int isFull(ListType *L) {
	return L->size==N;
}

void insertLast(ListType *L, element e) {
	if (isFull(L)) {
		printf("Full\n");
		return ;
	} else {
		L->data[L->size++] = e;
	}
}

void print(ListType *L) {
	for(int i =0; i<L->size; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

void insert(ListType *L, int pos, element e) {
	if (isFull(L)) {
		printf("Full\n");
		return;	
	}
	if (pos<0 || pos>L->size) {
		printf("invalid pos\n");
		return;
	}
	for(int i =(L->size-1); i>=pos; i--) {
		L->data[i+1] = L->data[i];
	}
	L->data[pos] = e;
	L->size++;
}

element deleteLast(ListType *L) {
	if (isEmpty(L)) {
		printf("empty\n");
		return -1;
	} else {
		return L->data[--L->size];
	}
}

element deletePos(ListType *L, int pos) {
	element e = L->data[pos];
	for(int i = pos; i < L->size-1; i++) {
		L->data[i] = L->data[i+1];
	}
	L->size--;
	return e;
}

int main() {
	ListType L;
	init(&L);
	insertLast(&L, 12);
	insertLast(&L, 14);
	insert(&L, 0, 10);
	insert(&L, 1, 1);
	print(&L);
	deletePos(&L, 1);
	deletePos(&L, 2);
	print(&L);
	return 0;
}
