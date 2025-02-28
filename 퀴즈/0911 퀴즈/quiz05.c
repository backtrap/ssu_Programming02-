#include <stdio.h>

int main(void) {

char a[2][3][7]={"dog", "cat", "horse", "pig", "duck", "bird"};

printf("%c %s\n", a[0][2][3], &a[1][2][2]);

// 배열표현으로만 코드 작성 (대괄호와 주소연산자만 사용)

printf("%c %s\n", *(*(*a+1)+2), (*(*(a+1)+1)+2));

// 포인터연산으로만 코드 작성 (* 와 + 연산자, 소괄호만 사용)

return 0;

}
