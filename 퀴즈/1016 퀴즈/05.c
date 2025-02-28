#include <stdio.h>
#include <termio.h>

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

int main(void){
	char a='a';
	int ch;

	printf("%c\n", a);

	ch=getch();
	
	printf("%c\n", ch);

	if(ch=='a')
		printf("Good");
	else
		printf("Bad");

	return 0;
}
