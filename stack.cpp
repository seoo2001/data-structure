#include <stdio.h>
#include <stdlib.h>

# define N 100

typedef struct StackType {
	int top;
	char stack[N];
}StackType;

void init(StackType* s) {
	s->top=-1;
}

bool isEmpty(StackType* s) {
	return s->top==-1;
}

bool isFull(StackType* s) {
	return s->top==N-1;
}

void push(StackType* s, char c) {
	if (isFull(s)) {
		printf("Overflow\n");	
	} else {
		s->top++;
		s->stack[s->top] = c;
	}
}

void print(StackType* s) {
	for(int i=0; i<=s->top; i++) {
		printf("%c\n", s->stack[i]);
	}
}

char pop(StackType* s) {
	if(isEmpty(s)) {
		printf("Empty\n");
		return '.';
	} else {
		char c = s->stack[s->top];
		s->top--;
		return c;
	}
}

char peak(StackType* s) {
	if(isEmpty(s)) {
		printf("Empty\n");
		return '.';
	} else {
		return s->stack[s->top];
	}
}

int main() {
	StackType s1;
	init(&s1);
	push(&s1, 'a');
	push(&s1, 'b');
	push(&s1, 'c');
	print(&s1);
	printf("%c\n", pop(&s1));
	printf("%c\n", peak(&s1));
	return 0;
}
