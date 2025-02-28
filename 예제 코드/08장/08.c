#include <stdio.h>

typedef struct grade {
	int grade[3];
	char p_f[3];
	int sum;
	float avg;
} grade;

int grade_proc3(grade * stp) {
	if (stp == NULL) {
		printf("오류 : NULL 포인터\n");
		return -1;
	}

	stp->sum = stp->grade[0] + stp->grade[1] + stp->grade[2];
	stp->avg = stp->sum/3.0;

	stp->p_f[0] = stp->grade[0] < 60 ? 'f' : 'p';
	stp->p_f[1] = stp->grade[1] < 60 ? 'f' : 'p';
	stp->p_f[2] = stp->grade[2] < 60 ? 'f' : 'p';

	return 0;
}

int main(void) {
	grade st = {{0}, {0}, -1, -1.0};

	printf("성적 입력(국어, 산수, 과학) : ");
	scanf("%d%d%d", &st.grade[0], &st.grade[1], &st.grade[2]);

	if (grade_proc3(&st))
		return 1;

	printf("국어 : %d (%c)\n", st.grade[0], st.p_f[0]);
	printf("산수 : %d (%c)\n", st.grade[1], st.p_f[1]);
	printf("과학 : %d (%c)\n", st.grade[2], st.p_f[2]);
	printf("총점 : %d\n", st.sum);
	printf("평균 : %.2f\n", st.avg);

	return 0;
}
	
