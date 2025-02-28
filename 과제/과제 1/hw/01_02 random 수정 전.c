#include stdio.h
#include stdlib.h
#include time.h
#include string.h
#include unistd.h

#define N 100

typedef struct word {
	char eng[N];
	char kor[N];
} word;

void flashCard01(const word []);
void flashCard02(const word []);
void game(const word []);

char  title =  영어 단어 암기 프로그램 ;
char  title_flashCard =  영어 단어 암기 프로그램  플래쉬카드 ;
char  title_game =  영어 단어 암기 프로그램  게임 ;

int main() {
	word dictionary[7][10] = {
		{  1일차
			{elephant, 코끼리},
			{house, 집},
			{orange, 오렌지},
			{bicycle, 자전거},
			{garden, 정원},
			{keyboard, 키보드},
			{river, 강},
			{mountain, 산},
			{island, 섬},
			{planet, 행성}
		},
		{  2일차
			{laptop, 노트북},
			{strawberry, 딸기},
			{candle, 양초},
			{guitar, 기타},
			{camera, 카메라},
			{notebook, 공책},
			{glasses, 안경},
			{scissors, 가위},
			{wallet, 지갑},
			{clock, 시계}
			},
		{  3일차
			{bread, 빵},
			{jungle, 정글},
			{volcano, 화산},
			{snow, 눈},
			{desert, 사막},
			{cloud, 구름},
			{forest, 숲},
			{beach, 해변},
			{waterfall, 폭포},
			{bridge, 다리}
		},
		{  4일차
			{violin, 바이올린},
			{piano, 피아노},
			{theater, 극장},
			{museum, 박물관},
			{library, 도서관},
			{restaurant, 식당},
			{bakery, 빵집},
			{market, 시장},
			{school, 학교},
			{hospital, 병원}
		},
		{  5일차
			{family, 가족},
			{friend, 친구},
			{emotion, 감정},
			{happiness, 행복},
			{confidence, 자신감},
			{curiosity, 호기심},
			{hope, 희망},
			{patience, 인내심},
			{sympathy, 동정심},
			{enthusiasm, 열정}
		},
		{  6일차
			{bread, 빵},
			{carrot, 당근},
			{chocolate, 초콜릿},
			{spoon, 숟가락},
			{fork, 포크},
			{plate, 접시},
			{knife, 칼},
			{microwave, 전자레인지},
			{refrigerator, 냉장고},
			{stove, 가스레인지}
		},
		{  7일차
			{doctor, 의사},
			{nurse, 간호사},
			{medicine, 약},
			{exercise, 운동},
			{nutrition, 영양},
			{hydration, 수분},
			{therapy, 치료},
			{rest, 휴식},
			{sleep, 잠},
			{energy, 에너지}
		}
	};

	int mode;
	int cardMode;  1이면 수동 모드, 2이면 자동 모드
	int day;

	system(clear);
	
	printf(%sn, title);
	printf(1. 플래쉬 카드		2. 게임		3. 프로그램 종료n);
	printf(n);

	printf(번호를 선택하세요  );
	scanf(%d, &mode);
	while (mode != 1 && mode !=2 && mode !=3) {
		printf(n보기에서 번호를 선택해 주세요  );
		scanf(%d, &mode);
	}

	if (mode == 3) {
		system(clear);
		
		return 0;
	}

	printf(학습 일차  );
	scanf(%d, &day);
	while (day != 1 && day != 2 && day != 3 && day != 4 && day != 5 && day != 6 && day != 7) {
		printf(n1~7일차 사이를 입력해주세요  );
		scanf(%d, &day);
	}
	
	if (mode == 1) {
		printf(출력 방식(수동모드  1, 자동모드  2)  );
		scanf(%d, &cardMode);
		
		while (cardMode != 1 && cardMode != 2) {
			printf(n수동모드  1과 자동모드  2 중에서 선택해 주세요  );
			scanf(%d, &cardMode);
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

	return ;
}

void flashCard02(const word arr []) {
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
	} while (n3 == n2  n3 == n1);
	
	do {
		srand(time(NULL));
		n4 = rand() % 10;
	} while (n4 == n3  n4 == n2  n4 == n1);

	do {
		srand(time(NULL));
		n5 = rand() % 10;
	} while (n5 == n4  n5 == n3  n5 == n2  n5 == n1);

	do {
		srand(time(NULL));
		n6 = rand() % 10;
	} while (n6 == n5  n6 == n4  n6 == n3  n6 == n2  n6 == n1);

	do {
		srand(time(NULL));
		n7 = rand() % 10;
	} while (n7 == n6  n7 == n5  n7 == n4  n7 == n3  n7 == n2  n7 == n1);

	do {
		srand(time(NULL));
		n8 = rand() % 10;
	} while (n8 == n7  n8 == n6  n8 == n5  n8 == n4  n8 == n3  n8 == n2  n8 == n1);

	do {
		srand(time(NULL));
		n9 = rand() % 10;
	} while (n9 == n8  n9 == n7  n9 == n6  n9 == n5  n9 == n4  n9 == n3  n9 == n2  n9 == n1);

	do {
		srand(time(NULL));
		n10 = rand() % 10;
	} while (n10 == n9  n10 == n8  n10 == n7  n10 == n6  n10 == n5  n10 == n4  n10 == n3  n10 == n2  n10 == n1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n1].eng);
	sleep(1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n1].kor);
	sleep(1);
		
	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n2].eng);
	sleep(1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n2].kor);
	sleep(1);
		
	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n3].eng);
	sleep(1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n3].kor);
	sleep(1);
		
	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n4].eng);
	sleep(1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n4].kor);
	sleep(1);
		
	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n5].eng);
	sleep(1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n5].kor);
	sleep(1);
		
	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n6].eng);
	sleep(1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n6].kor);
	sleep(1);
		
	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n7].eng);
	sleep(1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n7].kor);
	sleep(1);
		
	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n8].eng);
	sleep(1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n8].kor);
	sleep(1);
		
	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n9].eng);
	sleep(1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n9].kor);
	sleep(1);
		
	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n10].eng);
	sleep(1);

	system(clear);
	printf(%snnnn, title_flashCard);
	printf(%s, arr[n10].kor);
	sleep(1);

	return ;
}

void game(const word arr []) {

	return ;
}

