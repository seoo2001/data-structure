#include <stdio.h>

int main() {

	int a = 10;
	int b = a;
	
	printf("a = %d, b=%d\n", a, b);
	
	int *c; //���� �� �� * ��� -> ������ ���� ���� �ǹ�
	 
	c = &a;

	*c = 12; // a = 12
	
	int* d = c;
	
	

	printf("&a = %p, c=%p\n", &a, c);

	printf("a = %d, d=%p", a, d);

	return 0;
}
