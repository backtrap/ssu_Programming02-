#include <stdio.h>

#define PRN(x) printf(#x"\n"#x);

int main(void) {
	PRN(Hello from main());

	return 0;
}