#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define N 100

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
	word dictionary[7][10] = {
		{ // 1일차
			{"elephant", "코끼리"},
			{"house", "집"},
			{"orange", "오렌지"},
			{"bicycle", "자전거"},
			{"garden", "정원"},
			{"keyboard", "키보드"},
			{"river", "강"},
			{"mountain", "산"},
			{"island", "섬"},
			{"planet", "행성"}
		},
		{ // 2일차
			{"laptop", "노트북"},
			{"strawberry", "딸기"},
			{"candle", "양초"},
			{"guitar", "기타"},
			{"camera", "카메라"},
			{"notebook", "공책"},
			{"glasses", "안경"},
			{"scissors", "가위"},
			{"wallet", "지갑"},
			{"clock", "시계"}
			},
		{ // 3일차
			{"bread", "빵"},
			{"jungle", "정글"},
			{"volcano", "화산"},
			{"snow", "눈"},
			{"desert", "사막"},
			{"cloud", "구름"},
			{"forest", "숲"},
			{"beach", "해변"},
			{"waterfall", "폭포"},
			{"bridge", "다리"}
		},
		{ // 4일차
			{"violin", "바이올린"},
			{"piano", "피아노"},
			{"theater", "극장"},
			{"museum", "박물관"},
			{"library", "도서관"},
			{"restaurant", "식당"},
			{"bakery", "빵집"},
			{"market", "시장"},
			{"school", "학교"},
			{"hospital", "병원"}
		},
		{ // 5일차
			{"family", "가족"},
			{"friend", "친구"},
			{"emotion", "감정"},
			{"happiness", "행복"},
			{"confidence", "자신감"},
			{"curiosity", "호기심"},
			{"hope", "희망"},
			{"patience", "인내심"},
			{"sympathy", "동정심"},
			{"enthusiasm", "열정"}
		},
		{ // 6일차
			{"bread", "빵"},
			{"carrot", "당근"},
			{"chocolate", "초콜릿"},
			{"spoon", "숟가락"},
			{"fork", "포크"},
			{"plate", "접시"},
			{"knife", "칼"},
			{"microwave", "전자레인지"},
			{"refrigerator", "냉장고"},
			{"stove", "가스레인지"}
		},
		{ // 7일차
			{"doctor", "의사"},
			{"nurse", "간호사"},
			{"medicine", "약"},
			{"exercise", "운동"},
			{"nutrition", "영양"},
			{"hydration", "수분"},
			{"therapy", "치료"},
			{"rest", "휴식"},
			{"sleep", "잠"},
			{"energy", "에너지"}
		}
	};

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
			flashCard01(dictionary[day - 1]);
		else if (cardMode == 2)
			flashCard02(dictionary[day - 1]);
	}
	else if (mode == 2)
		game(dictionary[day - 1]);

	return 0;
}
	
void flashCard01(const word arr []) {
	// 랜덤 숫자 설정
	int num[10];
	int count = 0;

	srand(time(NULL));

	while (count < 10) {
		int index = rand() % 10;
		int duplicate = 0;

		for (int i = 0; i < count ; i++) {
			if (index == num[i]) {
				duplicate = 1;
				break;
			}
		}

		if (duplicate == 0) {
			num[count] = index;
			count++;
		}
	}

	// 엔터 치면 출력
	char c;
	int count_loop = 0;
	c = getchar();

	while (count_loop< 10) {
		system("clear");
		printf("%s\n\n\n\n", title_flashCard);
		printf("%s\n", arr[num[count_loop]].eng);

		if ((c = getchar()) == '\n') {	
			system("clear");
			printf("%s\n\n\n\n", title_flashCard);
			printf("%s\n", arr[num[count_loop]].kor);
		}

		if ((c = getchar()) == '\n')
				count_loop++;
	}
	
	main();

	return ;
}

void flashCard02(const word arr []) {
	// 랜덤 숫자 설정
	int num[10];
	int count = 0;

	srand(time(NULL));

	while (count < 10) {
		int index = rand() % 10;
		int duplicate = 0;

		for (int i = 0; i < count ; i++) {
			if (index == num[i]) {
				duplicate = 1;
				break;
			}
		}

		if (duplicate == 0) {
			num[count] = index;
			count++;
		}
	}
	
	// 숫자 출력
	for (int i = 0; i < 10; i++) {
		system("clear");
		printf("%s\n\n\n\n", title_flashCard);
		printf("%s\n", arr[num[i]].eng);
		sleep(1);
		system("clear");

		system("clear");
		printf("%s\n\n\n\n", title_flashCard);
		printf("%s\n", arr[num[i]].kor);
		sleep(1);
		system("clear");
	}

	main();

	return ;
}

void game(const word arr []) {
	int n;
	int length;
	int count = 1; // 시도할 때마다 +1
	int succeed = 1; // 1일 때 계속 도전, 다 맞추면 0 넣고 while() 탈출
	char c; // 게임 용
	
	srand(time(NULL));
	n = rand() % 10;

	length = strlen(arr[n].eng);
	char board[length + 1];
	for (int i = 0; i < length; i++) {
		board[i] = '_';
	}
	board[length] = '\0';

	printf("%s\n", board);
	printf("%s\n", arr[n].eng);
	printf("%s\n", arr[n].kor);
	
	getchar();
	if((c=getchar())=='\n') main();

	return ;
}

