#include <stdio.h>

typedef struct {
	int num;
	char name[10];
	int year;
}Student;

// ����ü�� ���� ���� ȣ����.	
Student up1(Student s) {
	s.year++;
	return s;
}

void up2(Student* s) {
	// *s.yaer++ �� �켱 ������ s.yaer�̱� ������ ���� �߻�
	// year�� �ּҰ��̸� ���� 
	
	s->year++; // (*s).year++; �� ���� 
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
