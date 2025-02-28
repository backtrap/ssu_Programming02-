#include <stdio.h>
#include <string.h>

int main () {
	char booklist[5][50] = {"Cygwin과 함께 배우는 C 프로그래밍", "C 99", "A book on C", "C 프로그래밍", "자바 프로그래밍"};
	
	char keyword[50];
	printf("검색 문장을 입력하세요 : ");
	scanf("%[^\n]", keyword);

	for (int i = 0; i < 5; i++) {
		if (strstr(booklist[i], keyword) != NULL)
			printf("%s \n", booklist[i]);
	}

	return 0;
}
