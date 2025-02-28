#include <stdio.h>

#define N 5

typedef struct name_grade {
	char name[10];
	int grade;
} name_grade;

int main() {
	int sum = 0, i;
	float avg = 0.0;

	name_grade st_a[N] = {{"하나", 77}, {"둘", 87}, {"셋", 65}, {"넷", 90}, {"다섯", 98}};
	
	printf("이름	점수\n");
	for (int i = 0; i < N; i++) {
		printf("%s	%d\n", st_a[i].name, st_a[i].grade);
		sum += st_a[i].grade;
	}

	avg = (float) sum/N;

	printf("성적 평균은 %.2f점입니다.\n", avg);

	return 0;
}
