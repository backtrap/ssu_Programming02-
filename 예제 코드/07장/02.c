#include <stdio.h>

int main() {
	int i, j = 5, *p;
	p = &i;
	i = 10;

	printf("(p = &i)i = %d, j = %d, *p = %d\n", i, j, *p);
	*p = *p * j;
	printf("(p = &i)i = %d, j = %d, *p = %d\n", i, j, *p);
	p = &j;
	printf("(p = &i)i = %d, j = %d, *p = %d\n", i, j, *p);

	return 0;
}
