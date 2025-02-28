#include <stdio.h>
unsigned long long count = 0;

int fibonacci_r(int n) {
	count++;

	if (n <= 1)
		return n;
	else 
		return (fibonacci_r(n - 1) + fibonacci_r(n - 2));
}

int main() {
	int n = fibonacci_r(44);
	printf("%lld, %d \n", count, n);

	return 0;
}
