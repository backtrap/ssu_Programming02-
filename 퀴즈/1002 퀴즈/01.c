#include <stdio.h>

struct info{

	char name[20]; // 이름

	double score; // 평점 평균

	int credit; // 취득 학점

};

void input_data(struct info [], int);

void scholarship(struct info [], int); 

int main(void)

{

	struct info students[5]; // 5명의 학생

	input_data(students, 5); // 이름, 평점 평균, 취득 학점을 입력받는 함수

	scholarship(students, 5); // 장학생의 이름, 평점 평균, 취득 학점을 출력하는 함수

	return 0;

}

void input_data(struct info arr [], int num) {
	for (int i; i < num; i++) {
		printf("학생의 이름을 입력하세요 : ");
		scanf("%s", (arr+i)->name);
		printf("평점 평균을 입력하세요 : ");
		scanf("%lf", &(arr[i].score));
		printf("취득 학점을 입력하세요 : ");
		scanf("%d", &(arr[i].credit));
	}

	return ;
}

void scholarship(struct info arr [], int num) {
	for (int i = 0; i < num; i++) {
		if (arr[i].credit>=20 && arr[i].score>=4.3) {
			printf("\n%s 학생은 장학생입니다.\n %s 학생의 취득 학점은 %d이고, 평균 평점은 %lf입니다.\n", (arr+i)->name, (arr+i)->name, arr[i].credit, arr[i].score);
		}
	}

	return ;
}
