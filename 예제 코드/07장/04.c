#include <stdio.h>

int main() {
	double x[10], *p, *q;

	p = &x[2];
	q = p + 5;

	printf("q - p = %ld\n", q - p);
	printf("(int)q - (int)p = %d\n", (int)q - (int)p);

	return 0;
}

