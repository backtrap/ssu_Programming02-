#include <stdio.h>
#include <string.h>

int main() {
	struct name_grade {
		char name[10];
		int grade;
	};

	struct name_grade st_g1, st_g2;

	strcpy(st_g1.name, "이순신");
	st_g1.grade = 98;
	strcpy(st_g2.name, st_g1.name);
	st_g2.grade = st_g1.grade;

	printf("%s의 점수는 %d점 입니다.\n", st_g2.name, st_g2.grade);

	return 0;
}

