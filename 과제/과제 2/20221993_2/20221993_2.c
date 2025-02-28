#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word {
	char eng[15];
	char kor[20];
	struct word * next;
} word;

void quiz(word * dict);

int main() {
	system("clear");
	FILE * fp;
	fp = fopen("./dict.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패");
		exit(1);
	}

	// dict.txt 동적 할당
	word * head = NULL;
	word * tail = NULL;
	word temp;

	int check;
	while (fscanf(fp, "%s %s", temp.eng, temp.kor) == 2) {
		word * temp02 = malloc(sizeof(word));
		strcpy(temp02->eng, temp.eng);
		strcpy(temp02->kor, temp.kor);
		temp02->next = NULL;

		if (head == NULL) {
			head = temp02;
			tail = head;
			
			// free(temp02);
		}
		else {
			tail->next = temp02;
			tail = temp02;

			// free(temp02);
		}
	}
	fclose(fp);

	// 동적할당 확인 코드
	/*
	int count = 0;
	word * temp03 = head;
	while (temp03 != NULL) {
		printf("%s %s\n", temp03->eng, temp03->kor);
		temp03 = temp03->next;
		count++;
	}
	printf("총 단어 수는 : %d\n", count);
	*/
	
	// 연결 리스트 정렬
	word * i;
	word * j;
	char tempEng[15];
	char tempKor[20];

	for (i = head; i != NULL; i = i->next) {
		for (j = i->next; j != NULL; j = j->next) {
			if (strcmp(i->eng, j->eng) > 0) {
				strcpy(tempEng, i->eng);
				strcpy(tempKor, i->kor);
				strcpy(i->eng, j->eng);
				strcpy(i->kor, j->kor);
				strcpy(j->eng, tempEng);
				strcpy(j->kor, tempKor);
			}
		}
	}
	
	// 연결리스트 정렬 확인 코드
	/*
	int count = 0;
	word * temp03 = head;
	while (temp03 != NULL) {
		printf("%s %s\n", temp03->eng, temp03->kor);
		temp03 = temp03->next;
		count++;
	}
	printf("총 단어 수는 : %d\n\n", count);		
	*/
	
	// 프로그램 실행 화면
	int button;
	printf(">> 영어 단어 맞추기 프로그램 <<\n");
	printf("1. 영어 단어 맞추기		2. 프로그램 종료\n\n");
	printf("번호를 선택하세요: ");
	scanf("%d", &button);

	if (button == 1)
		quiz(head);
	else if (button == 2) {
		system("clear");
		
		return 0;
	}
	else {
		printf("버튼을 잘못 입력하셨습니다. 1과 2 중 하나를 입력해야됩니다.\n다시 실행해주세요\n");

		return 0;
	}

	return 0;
}

void quiz(word * dict) {
	system("clear");
	printf(">> 영어 단어 맞추기 <<\n");
	float score = 0;
	char answer[10];
	int count = 0;
	int total = 0;
	word * i;
	int keep = 1;

	for (i = dict; i != NULL && keep == 1; i = i->next) {
		printf("%s -> ", i->kor);
		total++;
		scanf("%s", answer);
		getchar();

		if (strcmp(answer, ".quit") == 0) {
			total--;
			keep = 0;
			continue;

			break;
		}
		else if (strcmp(i->eng, answer) == 0) {
			printf("correct!\n");
			count++;
		}
		else {
			printf("incorrect!\n");
		}

		score = (float)count/total * 100;
	}

	printf("당신의 점수는 %.2f점입니다.\n", score);
	
	char c;
	while ((c =getchar()) != '\n')
	keep = 0;
	system("clear");

	main();
	
	return ;
}