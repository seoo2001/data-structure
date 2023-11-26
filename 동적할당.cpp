#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int *arr = (int *)malloc(sizeof(int)*n);
	
	srand(time(NULL));
	for(int i=0;i<n;i++) {
		arr[i] = rand() % 100;
	}
	for(int i=0;i<n;i++) {
		printf("%d\n", *(arr+i));
	}
	
	return 0;
}
