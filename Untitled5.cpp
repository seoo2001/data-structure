#include <stdio.h>

int main() {

	int a = 10;
	int b = a;
	
	printf("a = %d, b=%d\n", a, b);
	
	int *c; //선언 할 때 * 사용 -> 포인터 변수 임을 의미
	 
	c = &a;

	*c = 12; // a = 12
	
	int* d = c;
	
	

	printf("&a = %p, c=%p\n", &a, c);

	printf("a = %d, d=%p", a, d);

	return 0;
}
