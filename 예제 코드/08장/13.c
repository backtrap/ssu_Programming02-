#include <stdio.h>
#include <time.h>

typedef enum day {SUN, MON, TUE, WED, THU, FRI, SAT} day;

int main() {
	time_t now;
	day today;

	now = time(NULL);
	today = (now / (60*60*24) + 4) %7;

	switch (today) {
		case SUN :
			printf("오늘은 일요일 입니다. \n");
			break;
		case MON :
			printf("오늘은 월요일 입니다. \n");
			break;
		case TUE :
			printf("오늘은 화요일 입니다. \n");
			break;
		case WED :
			printf("오늘은 수요일 입니다. \n");
			break;
		case THU :
			printf("오늘은 목요일 입니다. \n");
			break;
		case FRI :
			printf("오늘은 금요일 입니다. \n");
			break;
		case SAT :
			printf("오늘은 토요일 입니다. \n");
			break;
		default :
			printf("time() 함수 오류입니다.\n");
	}

	return 0;
}
