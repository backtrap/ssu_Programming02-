#include <stdio.h>

typedef struct name_grade {
	char name[10];
	int grade;
} name_grade;

int main() {
	name_grade st, *st_p = &st;

	st = (name_grade) {"이순신", 98};

	printf("%s의 점수는 %d점 입니다.\n", st_p->name, (*st_p).grade);

	return 0;
}