#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main() {
	unsigned long long int a = time(NULL);
	printf("%llu\n", a);

	return 0;
}
