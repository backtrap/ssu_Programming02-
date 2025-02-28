#include <stdio.h>

int main(int argc, char * argv[]) {
	int i;

	printf("총 인자 개수 : %d\n", argc);

	for (int i = 0; i < argc; ++i)
		printf("%d번쨰 인자 : %s\n", i, argv[i]);

	return 0;
}
