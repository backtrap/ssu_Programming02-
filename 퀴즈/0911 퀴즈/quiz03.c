#include <stdio.h>

int main(void) {
int ary[5] = {10, 15, 20, 25, 30};

int *ap = ary;

printf("%p\n", ap);

printf("%p\n", &ary[2]);

printf("%p\n", &ap[3]);

printf("%p\n", ap+2);

printf("%p\n", ap);

printf("%d\n", ap[3]+1);

printf("%p\n", ary+2);

printf("%p\n", ary+2);

printf("%p\n", &ary[0]+2);

printf("%p\n", ary+2);

printf("%p\n", &*(ary+2));

return 0;
}