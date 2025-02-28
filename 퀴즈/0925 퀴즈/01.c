#include <stdio.h>
#include <time.h>

int main() {
	struct tm * t;
	time_t now;
	now = time(NULL);
	t = localtime(&now);

	char * wday = NULL;
	switch (t->tm_wday) {
		case 0 :
			wday = "일\0";
			break;
		case 1 :
			wday = "월\0";
			break;
		case 2 :
			wday = "화\0";
			break;
		case 3 :
			wday = "수\0";
			break;
		case 4 :
			wday = "목\0";
			break;
		case 5 :
			wday = "금\0";
			break;
		case 6 :
			wday = "토\0";
			break;	
	}

	int hour;
	char * ap = NULL;
	if (t->tm_hour>=12) {
		hour = t->tm_hour - 12;
		ap = "오후\0";
	}
	else {
		hour = t->tm_hour;
		ap = "오전\0";
	}
	
	printf("오늘은 %d년 %d월 %d일 %s요일 입니다.\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, wday);
	printf("현재 시간은 %s %d시 %d분 %d초입니다.\n", ap, hour, t->tm_min, t->tm_sec);
	
	return 0;
}

