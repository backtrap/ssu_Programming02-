#include <stdio.h>

int main() {
	char *p[3][2] = {"abc", "defg", "hi", "jklmno", "pqrstuvw", "xyz"};

	printf("%c\n", *(**p+2));
	printf("%c\n", *(*(*(p+1)+1)+2));
	printf("%s\n", *(*(p+1)+2));
	printf("%s\n", *(*(p+1)+1)+2);

	return 0;
}