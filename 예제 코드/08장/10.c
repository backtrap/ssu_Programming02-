#include <stdio.h>

typedef union number {
	int i;
	float f;
} number;

int main() {
	number num;
	num.i = 10;
	printf("i : %d	f : %f\n", num.i, num.f);

	num.f = 3.14;
	printf("i : %d	f : %f\n", num.i, num.f);

	return 0;
}
