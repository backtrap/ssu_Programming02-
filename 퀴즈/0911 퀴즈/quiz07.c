#include <stdio.h>

int main() {
	char * fruit = "strawberry";

	char c;
	int num = 0;

	while (1) {
		c = *(fruit + num);

		if (c == '\0')
			break;
		
		printf("%c", c);
		
		num++;
		num++;
	}

	return 0;
}
