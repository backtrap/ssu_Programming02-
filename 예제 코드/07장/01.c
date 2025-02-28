#include <stdio.h>

int main() {
	int i = 100;
	int *p;
	p = &i;

	printf("i 주소 : %p\n", &i);
	printf("i 값 : %d\n", i);
	printf("p 값 : %p\n", p);
	printf("*p값 : %d\n", *p);
	
	return 0;
}

