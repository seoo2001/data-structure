#include <stdio.h>

void swap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	printf("In swap1: a=%d, b=%d\n", a, b);
}

void swap2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("In swap2: a=%d, b=%d\n", *a, *b);
}

int main() {
	int a = 10;
	int b = 20;
	
	swap1(a, b);
	printf("a=%d, b=%d\n", a, b);
	
	swap2(&a, &b);
	printf("a=%d, b=%d\n", a, b);
	
	
	return 0;
}
