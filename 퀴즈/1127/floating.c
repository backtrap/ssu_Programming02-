#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void func(int sig);

int main() {
	signal(sig, func);
	int i, j;

	signal(sig, func);
	scanf("%d", &j);
	i = 7/j;

	printf("%d", i);

	return 0;
}
	
void func(int sig) {
	while (sig)
		printf("%d번 신호 발생\n", sig);

	exit(1);

	return ;
}

