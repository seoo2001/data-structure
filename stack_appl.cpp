#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

bool check(char expr[]) {
	StackType S;
	init(&S);
	char c, t;
	int n = strlen(expr);
	
	for (int i=0; i<n; i++) {
		c = expr[i];
		if (c=='(' || c=='{' || c=='[') {
			push(&S, c);
		} else if (c==')' || c=='}' || c==']') {
			t = pop(&S);
			if ((t=='(' && c!=')') ||
			    (t=='{' && c!='}') ||
			    (t=='[' && c!=']')) {
				return false;
			}
		}
	}
	if (isEmpty(&S)) {
		return true;
	} else return false;
}

int main() {
	char expr[N];
	scanf("%s", expr);
	
	if(check(expr)) {
		printf("success\n");
	} else {
		printf("fail\n");
	}
	
	return 0;
}
