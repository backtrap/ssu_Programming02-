#include <stdio.h>
// #include <string.h>

void mygets(char *);

int main(void) {
	char input[100];
	printf("문자열을 입력하세요 : ");
	mygets(input);

	printf("입력 문자열 : ");
	printf("%s", input);
	printf("입력 끝");

//	printf("\n %d \n", strlen(input));
	
	return 0;
}

void mygets(char * arr) {
	char c;
	int n = 0;

	while ((c=getchar())!='\n') {
		arr[n] = c;
		n++;
	}

	arr[n] = '\0';

	return ;
}
