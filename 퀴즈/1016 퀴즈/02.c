#include <stdio.h>

#define PRN_3(n, j, k) printf(#n " : %.1f, " #j " : %.1f, " #k " : %.1f // 변수  "#n ", " #j ", " #k"로 PRN_3(" #n ", " #j ", " #k ")를 사용했을 때\n", n, j, k);

int main() {
	float x = 1.1, y = 2.2, z = 3.3, a = 1.1, b = 2.2, c = 3.3;

	PRN_3(x, y, z);
	PRN_3(a, b, c);
	
	return 0;
}
