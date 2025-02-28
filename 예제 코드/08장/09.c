#include <stdio.h>

typedef union short_or_float {
	short s;
	float f;
} number;

int main() {
	number n;
	n.s = 2007;

	printf("s : %10d	f : %16.10e\n", n.s, n.f);

	n.f = 2007.0;

	printf("s : %10d	f : %16.10e\n", n.s, n.f);

	return 0;
}
