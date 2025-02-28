#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int a, b, c, d;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);
	d = (a + b + c)/3;

	printf("평균은 %d입니다.\n", d);

	return 0;
}