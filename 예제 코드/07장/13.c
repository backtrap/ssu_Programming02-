#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char * name;
    char temp[100];
    scanf("%s", temp);
    name = (char *)calloc(strlen(temp)+1, sizeof(char));
    strcpy(name, temp);
    
    printf("%s\n", name);
    
    char age[100];
    scanf("%s", age);
    
    printf("%s\n", age);
    
    return 0;
}