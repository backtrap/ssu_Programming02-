#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct friend {
    char * name;
    char * email;
    char * phone;
} friend;

void search(friend a[]);
void search_all(friend a[]);

int main() {
    friend arr[10];

    for (int i = 0; i < 10; i++) {
        arr[i].name = (char*) malloc(100 * sizeof(char));   
        arr[i].email = (char*) malloc(100 * sizeof(char));  
        arr[i].phone = (char*) malloc(100 * sizeof(char)); 
    }


    for (int i = 0; i < 10; i++) {
        printf("영문 이름과 이메일, 전화번호를 차례로 입력해주세요\n");
        scanf("%s %s %s", arr[i].name, arr[i].email, arr[i].phone);
    }

    search(arr);
    printf("\n");
    search_all(arr);

    for (int i = 0; i < 10; i++) {
        free(arr[i].name);
        free(arr[i].email);
        free(arr[i].phone);
    }

    return 0;
}

void search(friend a[]) {
    char * n = (char*) malloc(100 * sizeof(char));

    printf("찾고자 하는 영문 이름을 입력해주세요 : ");
    scanf("%s", n);

    for (int i = 0; i < 10; i++) {
        if (strcmp(a[i].name, n) == 0) {
            printf("%s의 이메일과 전화번호는 %s, %s.\n", a[i].name, a[i].email, a[i].phone);
            
	free(n);
            
	return ;
        }
    }

    printf("%s는 저장되어 있지 않습니다.\n", n);
    free(n); 

    return ;
}

void search_all(friend a[]) {
    for (int i = 0; i < 10; i++) {
        printf("%s의 이메일과 전화번호는 %s, %s.\n", a[i].name, a[i].email, a[i].phone);
    }

    return ;
}