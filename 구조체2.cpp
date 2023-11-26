#include<stdio.h>
#define N 20 
typedef struct Poly {
	int coef;
	int expon;	
}Poly;

Poly terms[N] = {{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}};
int avail = 6;

void print(int s, int e) {
	for(int i =s; i<=e; i++) {
		printf("%2dx^%d +", terms[i].coef, terms[i].expon);
	}
	printf(" \b\b \n");
}

void add(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {
	*Cs = avail;
	while(As<=Ae && Bs<= Be) {
		if (terms[As].expon==terms[Bs].expon) {
			if (terms[As].coef+terms[Bs].coef) {
				terms[avail].coef = terms[As].coef+terms[Bs].coef;
				terms[avail].expon = terms[As].expon;
				As++; Bs++;
				avail++;	
			}
		else if (terms[As].expon < terms[Bs].expon) {
			terms[avail].coef = 
		}
			
		}
	}
	
	*Ce = avail-1;
}

int main() {
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	print(As, Ae);
	print(Bs, Be);
	add(As, Ae, Bs, Be, &Cs, &Ce);
	return 0;
}
