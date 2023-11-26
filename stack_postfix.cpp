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
int evaluate(char postfix[]) {
	StackType S;
	init(&S);
	int op1, op2, value;
	char c;
	int n = strlen(postfix);
	
	for(int i = 0; i < n; i++) {
		c = postfix[i];
		if (c!='+' && c!='-' && c!='*' && c!='/') {
			value = c - '0';
			push(&S, value);
		} else {
			op2 = pop(&S);
			op1 = pop(&S);
			switch(c) {
				case '+': push(&S, op1+op2); break;
				case '-': push(&S, op1-op2); break;
				case '*': push(&S, op1*op2); break;
				case '/': push(&S, op1/op2); break;
			}
		}
	}
	return pop(&S);
}

int prec(int op) {
	switch(op) {
		case '(': case ')':
			return 0;
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
					
	}
}

void a(char infix[]) {
	StackType S;
	init(&S);
	char c, t;
	int n = strlen(infix);
	
	for(int i = 0; i<n; i++) {
		c = infix[i];
		switch(c) {
			case '+': case '-': case '*': case '/':
				while(!isEmpty(&S) && prec(c) <= prec(peak(&S)))
					printf("%c", pop(&S));
				push(&S, c);
				break;
			case '(':
				push(&S, c);
				break;
			case ')':
				t = pop(&S);
				while(t != '(') {
					printf("%c", pop(&S));
				}
			default:
				printf("%c", c);
				break;
		}
	}
	while(!isEmpty(&S)) {
		printf("%c", pop(&S));
	}
}


int main() {
//	char exprfix[N];
	char infix[N];
//	scanf("%s", exprfix);
//	printf("%d", evaluate(exprfix));
	
	scanf("%s", infix);
	a(infix);
	
	return 0;
}
