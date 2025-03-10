#include <stdio.h>
#include <stdlib.h>
#include <termio.h>

int getch(void);

int main() {
	system("ls");
	
	printf("몇 초 후에 화면을 지울까요? ");

	int sec;
	sec = getch();
	sec -= 48;

	printf("%d\n", sec);	
	sleep(sec);
	system("clear");

	return 0;
}

int getch(void) {
	int ch;
	struct termios buf;
	struct termios save;
	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch=getchar();
	tcsetattr(0, TCSAFLUSH, &save);

	return ch;
}
