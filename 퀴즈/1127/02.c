#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void myprintf(char * format, ...);

int main() {
	myprintf("gender : %c, age : %d\n", 'M', 20);
	
	return 0;
}

void myprintf(char * format, ...) {
	va_list ap;
	char * str;
	char c;
	int d;
	
	va_start(ap, format);
	while (*format) {
		if (strncmp(format, "%s", 2) == 0) {
			str = va_arg(ap, char *);
			while (*str) 
				putchar(*str++);

			format = format + 2;
		}
		else if (strncmp(format, "%c", 2) == 0) {
			c = va_arg(ap, int);
			putchar(c);

			format = format + 2;
		}
		else if (strncmp(format, "%d", 2) == 0) {
			d = va_arg(ap, int);
			putchar(d);
			
			format = format + 2;
		}
		else {
			putchar(*format);
			format++;
		}
	}

	va_end(ap);

	return ;
}

