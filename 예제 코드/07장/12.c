#include <stdio.h>
#include <string.h>

struct name_grade {
    char name[10];
    int grade;
};

int main() {
    struct name_grade st1;
    strcpy(st1.name, "이순신");
    
    printf("%s\n", st1.name);
    
    struct name_grade st2 = (struct name_grade){"이순신", 98};
    
    printf("%s\n", st2.name);
    
    struct name_grade st3 = {"이순신", 98};
    
    printf("%s\n", st3.name);
    
    struct name_grade st4;
    st4.name = "이순신";
    
    return 0;
}
