#include <stdio.h>

int iPower(int x, int n) {
	int result = 1;
	for(int i=0; i<n; i++) {
		result *= x;
	}
	return result;
}

int rPower(int x, int n) {
	if (n==0) return 1;
	else return x*rPower(x,n-1);
}

int Power(int x, int n) {
	if (n==0) return 1;
	else if (n%2==0) return Power(x*x, n/2);
	else return x * Power(x*x, (n-1)/2);
}

int Power0(int x, int n) {
	int ans = 1;
	while(n>0) {
		if (n%2) ans*=x;
		x*=x;
		n/=2;
	}
	return ans;
}

int main(void) {
	int x, n;
	scanf("%d %d", &x, &n);
	
	printf("%d, %d\n", iPower(x,n),rPower(x,n));
	printf("%d\n", Power(x,n));
	printf("%d\n", Power0(x,n));
	return 0;
}
