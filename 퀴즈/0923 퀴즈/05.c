#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void * p, const void * q);

int main() {
	char * arr[10];
	char temp[100];

	for (int i = 0; i < 10; i++) {
		printf("%d번째 단어를 입력하세요 : ", i+1);
		scanf("%s", temp);
		getchar();

		arr[i] = (char *)calloc(strlen(temp) + 1, sizeof(char));
		strcpy(arr[i], temp);		
	}

	qsort(arr, 10, sizeof(char), compare);
	
	for (int i = 0; i < 10; i++) {
		printf("%s\n", arr[i]);
	}

	return 0;
}

int compare(const void * p, const void * q) {
	char * str1 = (char *)p;
	char * str2 = (char *)q;

	if (strcmp(str1, str2)<0) {
		return -1;
	}
	else if (strcmp(str1, str2)>0) {
		return 1;
	}
}
