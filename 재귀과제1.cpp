//문제 1번 
#include <stdio.h>

int SumOneToN(int x) {
	if (x==1) return 1;
	return x+SumOneToN(x-1);
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d", SumOneToN(n));	
	return 0;
}

//문제 2번
#include <stdio.h>

void PrintDigit(int x) {

	int digit = x%10;
	if (x>=10) PrintDigit(x/10);
	printf("%d\n", digit);
}

int main(void) {
	int n;
	scanf("%d", &n);
	PrintDigit(n);	
	return 0;
} 

//문제 3번
#include <stdio.h>

void PrintDigit(int x) {

	int digit = x%10;
	printf("%d\n", digit);
	if (x>=10) PrintDigit(x/10);
}

int main(void) {
	int n;
	scanf("%d", &n);
	PrintDigit(n);	
	return 0;
}

//문제 4번
#include <stdio.h>
int n;
int num[20];

int FindMax(int idx) {
	if (idx==0) return num[idx];
	int temp = FindMax(idx-1);
	if (temp > num[idx]) return temp;
	else return num[idx];
}

int main(void) { 
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf(" %d", &num[i]);
	}	
	printf("%d", FindMax(n-1));
	return 0;
}

//문제 5번 
#include <stdio.h>

void Hanoi(int x, char s, char t, char e) {
	if (x==1) {
		printf("%c %c\n", s, e);
		return;
	}
	Hanoi(x-1, s, e, t);
	printf("%c %c\n", s, e);
	Hanoi(x-1, t, s, e);
}
int main(void) {
	int n;
	scanf("%d", &n);
	Hanoi(n, 'A', 'B', 'C');
	return 0;
}

//문제 6번
 #include <stdio.h>
 
 int gcd(int a, int b) {
 	if (b==0) return a;
 	return gcd(b, a%b);
 }
 
 int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n<m) {
		int temp = n;
		m = n;
		n = temp;
	}
	printf("%d", gcd(n,m));
	return 0;
 }
 
//문제 7번
#include <stdio.h>
char words[100];
char word;
int findc(char c, int idx) {
	if (idx>100 or !words[idx]) return 0;
	return (c==words[idx])+findc(c, idx+1);
}

int main(void) {
	scanf("%s\n", words);
	scanf("%c", &word);
	printf("%d", findc(word, 0));
	return 0;
}  
