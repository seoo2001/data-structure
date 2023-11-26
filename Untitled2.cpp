#include <stdio.h>

typedef struct {
	int num;
	char name[10];
	int year;
}Student;

// 구조체는 값에 의한 호출임.	
Student up1(Student s) {
	s.year++;
	return s;
}

void up2(Student* s) {
	// *s.yaer++ 는 우선 순위가 s.yaer이기 때문에 오류 발생
	// year가 주소값이면 맞음 
	
	s->year++; // (*s).year++; 와 같음 
}

int main() {
	Student s1;
	scanf("%d %s %d", &s1.num, s1.name, &s1.year);	
	printf("%d\n", s1.year);
	
	s1 = up1(s1);
	printf("%d\n", s1.year);
	
	up2(&s1);
	printf("%d\n", s1.year);
	
	return 0;
}
