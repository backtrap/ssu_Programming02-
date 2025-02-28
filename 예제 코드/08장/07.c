#include <stdio.h>

typedef struct grade {
	int grade[3];
	char p_f[3];
	int sum;
	float avg;
} grade;

grade grade_proc(grade st) {
	st.sum = st.grade[0] + st.grade[1] + st.grade[2];
	st.avg = st.sum / 3.0;
	st.p_f[0] = st.grade[0] < 60 ? 'f' : 'p';
	st.p_f[1] = st.grade[1] < 60 ? 'f' : 'p';
	st.p_f[2] = st.grade[2] < 60 ? 'f' : 'p';

	return st;
}

int main(void) {
	grade st = {{0}, {0}, -1, -1.0};

	printf("성적 입력(국어, 산수, 과학) : ");
	scanf("%d%d%d", &st.grade[0], &st.grade[1], &st.grade[2]);

	st = grade_proc(st);

	printf("국어 : %d (%c)\n", st.grade[0], st.p_f[0]);
	printf("산수 : %d (%c)\n", st.grade[1], st.p_f[1]);
	printf("과학 : %d (%c)\n", st.grade[2], st.p_f[2]);
	printf("총점 : %d\n", st.sum);
	printf("평균 : %.2f\n", st.avg);

	return 0;
}
