#include <stdio.h>

int main() {
	char a = 0xff;
	short b = 0xffff;
	int c = 0xffffffff;
	long long d = 0xffffffffff;

	printf("문제 그대로 출력 \n");
	printf("%c\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);

	printf("내 정답\n");
	printf("%#hhx\n", a);
	printf("%#hx\n", b);
	printf("%#x\n", c);
	printf("%#llx\n", d);
	
	return 0;
}