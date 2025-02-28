#include <stdio.h>

typedef struct {
	char name[100];
	int grade;
} name_grade;

typedef struct {
	char name[100];
	name_grade student1, student2, student3;
	float avg;
} subject;

int main() {
	subject math = {"수학", {"하나", 90}, {"둘", 44}, {"셋", 76}};

	math.avg = (math.student1.grade + math.student2.grade + math.student3.grade)/3.0;

	printf("%s : %d 점 \n", math.student1.name, math.student1.grade);
	printf("%s : %d 점 \n", math.student2.name, math.student2.grade);
	printf("%s : %d 점 \n", math.student3.name, math.student3.grade);
	printf("%s 평균은 %.2f점 입니다.\n", math.name, math.avg);

	return 0;
}
