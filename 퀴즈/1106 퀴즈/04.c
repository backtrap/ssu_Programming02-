#include <stdio.h>

int main() {
FILE * f = fopen("./employee.txt", "r");
char temp[10000];
fprintf(f, "%s", temp);
printf("%s", temp);

return 0;
}