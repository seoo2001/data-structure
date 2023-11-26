#include <stdio.h>
#include <stdlib.h>
#define N 20

typedef struct Poly {
	int degree;
	int coef[N];
}Poly;

void print(Poly p) {
	int c, e;
	for(c=0, e=p.degree; c<=p.degree; c++, e--) {
		printf("%2dx^%d + ", p.coef[c], e);
	}
	printf("\b\b \n");
}

Poly add(Poly p1, Poly p2) {
	Poly p;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degA = p1.degree;
	int degB = p2.degree;
	p.degree = (degA > degB) ? degA : degB;
	while(Apos<=p1.degree && Bpos<=p2.degree) {
		if (degA > degB) {
			p.coef[Cpos] = p1.coef[Apos];
			Apos++; Cpos++;
			degA--;
		}
		else if (degA==degB) {
			p.coef[Cpos] = p1.coef[Apos]+p2.coef[Bpos];
			Apos++; Bpos++; Cpos++; 
			degA--; degB--;
		}
		else {
			p.coef[Cpos] = p2.coef[Apos];
			Bpos++; Cpos++;
			degB--;
		}
	}
	return p;
}

int main() {
	Poly a, b, c;
	
	scanf("%d %d", &a.degree, &b.degree);
	for(int i=0; i<=a.degree; i++) {
		scanf("%d", &a.coef[i]);
	} 
	for(int i=0; i<=b.degree; i++) {
		scanf("%d", &b.coef[i]);
	} 
	print(a);
	print(b);
	c=add(a,b);
	print(c);
	
	
	return 0;
}
