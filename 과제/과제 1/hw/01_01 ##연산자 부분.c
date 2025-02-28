#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 100
#define NUM(i) n ## i

typedef struct word {
	char eng[N];
	char kor[N];
} word;

void flashCard01(const word []);
void flashCard02(const word []);
void game(const word []);

char * title = ">> 영어 단어 암기 프로그램 <<";
char * title_flashCard = ">> 영어 단어 암기 프로그램 : 플래쉬카드 <<";
char * title_game = ">> 영어 단어 암기 프로그램 : 게임 <<";

int main() {
	word dictionary[7][10];
	int mode;
	int cardMode; // 1이면 수동 모드, 2이면 자동 모드
	int day;

	system("clear");
	
	printf("%s\n", title);
	printf("1. 플래쉬 카드		2. 게임		3. 프로그램 종료\n");
	printf("\n");

	printf("번호를 선택하세요 : ");
	scanf("%d", &mode);
	while (mode != 1 && mode !=2 && mode !=3) {
		printf("\n보기에서 번호를 선택해 주세요 : ");
		scanf("%d", &mode);
	}

	if (mode == 3) {
		system("clear");
		
		return 0;
	}

	printf("학습 일차 : ");
	scanf("%d", &day);
	while (day != 1 && day != 2 && day != 3 && day != 4 && day != 5 && day != 6 && day != 7) {
		printf("\n1~7일차 사이를 입력해주세요 : ");
		scanf("%d", &day);
	}
	
	if (mode == 1) {
		printf("출력 방식(수동모드 : 1, 자동모드 : 2) : ");
		scanf("%d", &cardMode);
		
		while (cardMode != 1 && cardMode != 2) {
			printf("\n수동모드 : 1과 자동모드 : 2 중에서 선택해 주세요 : ");
			scanf("%d", &cardMode);
		}

		if (cardMode == 1)
			flashCard01(dictionary[day]);
		else if (cardMode == 2)
			flashCard02(dictionary[day]);
	}
	else if (mode == 2)
		game(dictionary[day]);

	return 0;
}
	
void flashCard1(const word arr []) {
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
	
	srand(time(NULL));
	n1 = rand() % 10;
	
	do {
		srand(time(NULL));
		n2 = rand() % 10;
	} while (n2 == n1);
	
	do {
		srand(time(NULL));
		n3 = rand() % 10;
	} while (n3 == n2 || n3 == n1);
	
	do {
		srand(time(NULL));
		n4 = rand() % 10;
	} while (n4 == n3 || n4 == n2 || n4 == n1);

	do {
		srand(time(NULL));
		n5 = rand() % 10;
	} while (n5 == n4 || n5 == n3 || n5 == n2 || n5 == n1);

	do {
		srand(time(NULL));
		n6 = rand() % 10;
	} while (n6 == n5 || n6 == n4 || n6 == n3 || n6 == n2 || n6 == n1);

	do {
		srand(time(NULL));
		n7 = rand() % 10;
	} while (n7 == n6 || n7 == n5 || n7 == n4 || n7 == n3 || n7 == n2 || n7 == n1);

	do {
		srand(time(NULL));
		n8 = rand() % 10;
	} while (n8 == n7 || n8 == n6 || n8 == n5 || n8 == n4 || n8 == n3 || n8 == n2 || n8 == n1);

	do {
		srand(time(NULL));
		n9 = rand() % 10;
	} while (n9 == n8 || n9 == n7 || n9 == n6 || n9 == n5 || n9 == n4 || n9 == n3 || n9 == n2 || n9 == n1);

	do {
		srand(time(NULL));
		n10 = rand() % 10;
	} while (n10 == n9 || n10 == n8 || n10 == n7 || n10 == n6 || n10 == n5 || n10 == n4 || n10 == n3 || n10 == n2 || n10 == n1);

	for (int i = 1; i < 11; i++) {
		system("clear");
		printf("%s\n\n\n\n", title_flashCard);
		printf("%s", arr[NUM(i)].eng);
		sleep(1000);

		system("clear");
		printf("%s\n\n\n\n", title_flashCard);
		printf("%s", arr[NUM(i)].kor);
		sleep(1000);
		
	}

	return ;
}

void flashCard2(const word arr []) {

	return ;
}

void game(const word arr []) {

	return ;
}

