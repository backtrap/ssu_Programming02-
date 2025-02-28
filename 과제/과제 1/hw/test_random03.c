#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int num[10];
	int count = 0;

	srand(time(NULL));

	while (count < 10) {
		int index = rand() % 10;
		int duplicate = 0;

		for (int i = 0; i < count ; i++) {
			if (index == num[i]) {
				duplicate = 1;
				break;
			}
		}

		if (duplicate == 0) {
			num[count] = index;
			count++;
		}
	}

	for (int i = 0; i < 10; i++) 
		printf("%d번쨰 숫자는 : %d\n", i + 1, num[i]);
	
	return 0;
}
