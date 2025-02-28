#include <stdio.h>

int main() {
	int a = 33333, b = -77777, c = 0, d = 0, e = 0;
	c = a & b;
	d = a | b;
	e = a ^ b;

	printf("a : %x, b : %x\n", a, b);
	printf("a & b : %x\n", c);
	printf("a | b : %x\n", d);
	printf("a ^ b : %x\n", e);

	return 0;
}
