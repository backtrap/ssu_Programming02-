#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main() {
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
	
	srand(time(NULL));
	n1 = rand() % 10;
	
	do {
		n2 = rand() % 10;
	} while (n2 == n1);
	
	do {
		n3 = rand() % 10;
	} while (n3 == n2 || n3 == n1);
	
	do {
		n4 = rand() % 10;
	} while (n4 == n3 || n4 == n2 || n4 == n1);

	do {
		n5 = rand() % 10;
	} while (n5 == n4 || n5 == n3 || n5 == n2 || n5 == n1);

	do {
		n6 = rand() % 10;
	} while (n6 == n5 || n6 == n4 || n6 == n3 || n6 == n2 || n6 == n1);

	do {
		n7 = rand() % 10;
	} while (n7 == n6 || n7 == n5 || n7 == n4 || n7 == n3 || n7 == n2 || n7 == n1);

	do {
		n8 = rand() % 10;
	} while (n8 == n7 || n8 == n6 || n8 == n5 || n8 == n4 || n8 == n3 || n8 == n2 || n8 == n1);

	do {
		n9 = rand() % 10;
	} while (n9 == n8 || n9 == n7 || n9 == n6 || n9 == n5 || n9 == n4 || n9 == n3 || n9 == n2 || n9 == n1);

	do {
		n10 = rand() % 10;
	} while (n10 == n9 || n10 == n8 || n10 == n7 || n10 == n6 || n10 == n5 || n10 == n4 || n10 == n3 || n10 == n2 || n10 == n1);

	printf("%d\n", n1);
	printf("%d\n", n2);
	printf("%d\n", n3);
	printf("%d\n", n4);
	printf("%d\n", n5);
	printf("%d\n", n6);
	printf("%d\n", n7);
	printf("%d\n", n8);
	printf("%d\n", n9);
	printf("%d\n", n10);

	return 0;
}