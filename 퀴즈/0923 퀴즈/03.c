#include <stdio.h>

int main(void)

{

	char s[] = "abc";

	char *p = s;

	*p = 'A';

	printf("%s\n", s);

return 0;

}