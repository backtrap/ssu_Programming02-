#include <stdio.h>
#include <stdarg.h>

int add(int num, ...);

int main() {
	int sum01 = add(3, 4, 5, 6);
	printf("%d\n", sum01);

	int sum02 = add(4, 6, 2, 4, 8);
	printf("%d\n", sum02);

	int sum03 = add(5, 1, 2, 6, 7, 10);
	printf("%d\n", sum03);

	return 0;
}

int add(int num, ...) {
	int sum = 0;
	va_list ap;

	va_start(ap, num);
	while (num != 0) {
		sum += va_arg(ap, int);
		num--;
	}

	return sum;
}
