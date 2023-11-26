#include <stdio.h>
#include <stdlib.h>
#define N 20

typedef int element;
typedef struct {
	int top;
	element stack[N];
}StackType;

void init(StackType *S) {
	S->top = -1;
}

int isEmpty(StackType *S) {
	return S->top==-1;
}

int isFull(StackType *S) {
	return S->top==N-1;
}

void push(StackType *S, element e) {
	if (not isFull(S)) {
		S->stack[++S->top] = e;
	}
}

element peek(StackType *S) {
	if (isEmpty(S)) {
		return 0;
	}
	return S->stack[S->top];
}

element pop(StackType *S) {
	if (isEmpty(S)) {
		return 0;
	}
	return S->stack[S->top--];
}

void sortedPush(StackType *S, element e) {
	if (isEmpty(S) || e > peek(S)) {
		push(S, e);
	}
	else {
		element temp = pop(S);
		sortedPush(S, e);
		push(S, temp);
	}
} 

void print(StackType *S) {
	for(int i=0; i<=S->top; i++) {
		printf("%d ", S->stack[i]);
	}
}

int main() {
	StackType S;
	init(&S);
	element data[6] = {5, 3, 8, 1, 2, 7};
	for(int i=0; i<6; i++) {
		sortedPush(&S, data[i]);
		print(&S);
	}
	return 0;
}
