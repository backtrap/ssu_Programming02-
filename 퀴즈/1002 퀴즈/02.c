#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[20];
	int id;
	char score[10];
} student;

int main () {
	int num;
	printf("학생 수를 입력하세요 : ");
	scanf("%d", &num);

	student arr[num];

	for (int i = 0; i < num; i++) {
		printf("이름, 학번, 성적을 입력하세요 : ");
		scanf("%s %d %s", arr[i].name, &(arr[i].id), arr[i].score);
	}
	
for (int i = 0; i <= num; i++) {
for (int j = 0; j < num; j++) {
if (strcmp(arr[i].score, "A+")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "A0")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "A-")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "B+")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "B0")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "B-")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "C+")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "C0")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "C-")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "D+")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "D0")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "D-")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		i++; 
		continue;
	}
	else if (strcmp(arr[i].score, "F")==0) {
		printf("%s		%d		%s\n", arr[i].name, arr[i].id, arr[i].score);
		j++; 
		continue;
	}
}
}
	return 0;
}
