#include <stdio.h>

int main(void)

{

int a = 100, *p = &a, **q = &p, ***r = &q;

printf("%p %p %p %p %p\n", &a, p, q, r, *r);

printf("%p %p %p %p %p\n", &a+1, p+1, q+1, r+1, *r+1);

return 0;

}
