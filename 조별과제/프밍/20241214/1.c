#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

client_s *client_head = NULL;
book_s *book_head = NULL;
borrow_s *borrow_head = NULL;
int loop_main = 1;
int N = 0;

void get_client() {
    FILE *cl = fopen("client", "r");
    if (cl == NULL) {
        printf("클라이언트 파일을 열 수 없습니다.\n");
        return;
    }

    while (1) {
        client_s *temp = (client_s *)malloc(sizeof(client_s));
        if (temp == NULL) {
            printf("메모리 할당 실패\n");
            fclose(cl);
            return;
        }

        // fscanf로 데이터를 읽어옵니다.
        int result = fscanf(cl, "%d | %s | %s | %[^|] | %s", 
                            &temp->studentnum,
                            temp->password,
                            temp->name,
                            temp->address,
                            temp->phonenum);
        int len = strlen(temp->address);
        while (len > 0 && temp->address[len - 1] == ' ') {
            temp->address[len - 1] = '\0';
            len--;
        }

        if (result == 5) { // 성공적으로 모든 데이터를 읽은 경우
            temp->next = NULL;

            if (client_head == NULL) {
                client_head = temp; // 첫 노드인 경우
            } else {
                client_s *cur = client_head;
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = temp; // 마지막 노드에 추가
            }
        } else { // fscanf 실패 시 메모리 해제 및 루프 종료
            free(temp);
            break;
        }
    }

    fclose(cl);
}


void get_book() {
    FILE *bk = fopen("book", "r");
    if (bk == NULL) {
        printf("도서 파일을 열 수 없습니다.\n");
        return;
    }

    while (1) {
        book_s *temp = (book_s *)malloc(sizeof(book_s));
        if (temp == NULL) {
            printf("메모리 할당 실패\n");
            fclose(bk);
            return;
        }

        // fscanf로 데이터를 읽어옵니다.
        int result = fscanf(bk, "%d | %s | %s | %s | %lld | %s | %c",
                            &temp->booknum,
                            temp->bookname,
                            temp->publisher,
                            temp->author,
                            &temp->ISBN,
                            temp->location,
                            &temp->available);

        if (result == 7) { // 성공적으로 모든 데이터를 읽은 경우
            temp->next = NULL;
	        N++;

            if (book_head == NULL) {
                book_head = temp; // 첫 노드인 경우
            } else {
                book_s *cur = book_head;
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = temp; // 마지막 노드에 추가
            }
        } else { // fscanf 실패 시 메모리 해제 및 루프 종료
            free(temp);
            break;
        }
    }

    fclose(bk);
}


void get_borrow() {
    FILE *br = fopen("borrow", "r");
    if (br == NULL) {
        printf("대여 파일을 열 수 없습니다.\n");
        return;
    }

    while (1) {
        borrow_s *temp = (borrow_s *)malloc(sizeof(borrow_s));
        if (temp == NULL) {
            printf("메모리 할당 실패\n");
            fclose(br);
            return;
        }

        // fscanf로 데이터를 읽어옵니다.
        int result = fscanf(br, "%d | %d | %ld | %ld",
                            &temp->studentnum,
                            &temp->booknum,
                            &temp->borrowdate,
                            &temp->returndate);

        if (result == 4) { // 성공적으로 모든 데이터를 읽은 경우
            temp->next = NULL;

            if (borrow_head == NULL) {
                borrow_head = temp; // 첫 노드인 경우
            } else {
                borrow_s *cur = borrow_head;
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = temp; // 마지막 노드에 추가
            }
        } else { // fscanf 실패 시 메모리 해제 및 루프 종료
            free(temp);
            break;
        }
    }

    fclose(br);
}


void sort_clients() {
    client_s *i, *j;
    int temp_studentnum;
    char temp_password[15], temp_name[20], temp_address[20], temp_phonenum[20];

    for (i = client_head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->studentnum > j->studentnum) {
                // studentnum 교환
                temp_studentnum = i->studentnum;
                i->studentnum = j->studentnum;
                j->studentnum = temp_studentnum;

                // password 교환
                strcpy(temp_password, i->password);
                strcpy(i->password, j->password);
                strcpy(j->password, temp_password);

                // name 교환
                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);

                // address 교환
                strcpy(temp_address, i->address);
                strcpy(i->address, j->address);
                strcpy(j->address, temp_address);

                // phonenum 교환
                strcpy(temp_phonenum, i->phonenum);
                strcpy(i->phonenum, j->phonenum);
                strcpy(j->phonenum, temp_phonenum);
            }
        }
    }
}


void sort_books() {
    if (book_head == NULL) return; // 리스트가 비어 있으면 정렬할 필요 없음

    book_s *i, *j;
    for (i = book_head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->ISBN > j->ISBN) {
                // 노드 데이터 교환 대신 노드 자체를 교환
                // 전체 노드를 교환하기 위해 임시 포인터를 사용
                book_s temp = *i;
                *i = *j;
                *j = temp;

                // 연결 리스트의 next 포인터 복구
                book_s *temp_next = i->next;
                i->next = j->next;
                j->next = temp_next;
            }
        }
    }
}

int membership(){
    int studentnum;
    char password[15], name[20], address[20], phonenum[20];
    client_s *cur = client_head;
    printf("회원 가입을 시작합니다.\n");
    int new = 0;
    while (!new){
        new = 1;
        printf("학번: ");
        scanf("%d", &studentnum);
        while (cur !=NULL){
            if (cur->studentnum == studentnum){
                printf("이미 존재하는 학번입니다.\n");
                new = 0;
                break;
            }
            cur = cur->next;
        }
    } 
    
    printf("비밀번호: ");
    scanf(" %[^\n]", password);

    printf("이름: ");
    scanf(" %[^\n]", name);

    printf("주소: ");
    scanf(" %[^\n]", address);

    printf("전화번호: ");
    scanf(" %[^\n]", phonenum);
    
    client_s *new_client;
    new_client = (client_s *)malloc(sizeof(client_s));
    new_client->studentnum = studentnum;
    strcpy(new_client->password, password);
    strcpy(new_client->name, name);
    strcpy(new_client->address, address);
    strcpy(new_client->phonenum, phonenum);
    new_client->next = client_head;
    client_head = new_client;
    sort_clients();
    FILE *cl = fopen("client","w");
    cur = client_head;
    while (cur != NULL) {
        fprintf(cl, "%d | %s | %s | %s | %s\n",cur->studentnum, cur->password, cur->name, cur->address, cur->phonenum);
        cur = cur->next;
    }
    fclose(cl);
    printf("회원 가입이 완료되었습니다.\n\n\n"); // "Enter을 눌러 메뉴로 이동하세요." 부분 삭제
    while(getchar()!='\n');
    //system("clear"); TODO : clear 삭제 
    //client_func(studentnum);
    save_all_data();
    return 1;
}

int login() {
    client_s *now = client_head;
    char logname[15];
    char password[15];

    printf("로그인 시작\n");
    printf("학번: ");
    scanf("%s", logname);
    printf("비밀번호: ");
    scanf("%s", password);

    // 관리자 로그인
    if (strcmp(logname, "admin") == 0) {
        if (strcmp(password, "lib_admin7") == 0) {
            printf("관리자님, 반갑습니다.\n");
            // 관리자 기능 호출
            admin_func();
            return 0;
        } else {
            printf("관리자 비밀번호가 틀렸습니다.\n");
            return 0;
        }
    }

    // 일반 사용자 로그인
    int num = atoi(logname);
    if (num == 0) {
        printf("유효하지 않은 학번입니다.\n");
        return 0;
    }

    while (now != NULL) {
        if (num == now->studentnum && strcmp(now->password, password) == 0) {
            printf("%s님, 반갑습니다.\n", now->name);
            // 사용자 기능 호출
            client_func(num);
            return 0;
        }
        now = now->next;
    }

    printf("로그인명 혹은 비밀번호가 일치하지 않습니다.\n");
    return 0;
}


int libservice() {
START:
    int num;
    printf(">> 도서관 서비스 <<\n");
    printf("1. 회원 가입        2. 로그인        3. 프로그램 종료\n");
    printf("\n번호를 선택하세요: ");
    scanf("%d", &num);

    if (num == 1) {
        membership();
        // TODO
        goto START;
    } else if (num == 2) {
        login();
    } else {
        loop_main = 0;
        return 0;
    }
    return 1;
}


void save_all_data() {

    sort_clients();
    sort_books();

    // 클라이언트 데이터 저장
    FILE *client_file = fopen("client", "w");
    if (client_file != NULL) {
        client_s *cur_client = client_head;
        while (cur_client != NULL) {
            fprintf(client_file, "%d | %s | %s | %s | %s\n",
                    cur_client->studentnum, cur_client->password, cur_client->name,
                    cur_client->address, cur_client->phonenum);
            cur_client = cur_client->next;
        }
        fclose(client_file);
    }

    // 도서 데이터 저장
    FILE *book_file = fopen("book", "w");
    if (book_file != NULL) {
        book_s *cur_book = book_head;
        while (cur_book != NULL) {
            fprintf(book_file, "%d | %s | %s | %s | %lld | %s | %c\n",
                    cur_book->booknum, cur_book->bookname, cur_book->publisher,
                    cur_book->author, cur_book->ISBN, cur_book->location, cur_book->available);
            cur_book = cur_book->next;
        }
        fclose(book_file);
    }

    // 대여 데이터 저장
    FILE *borrow_file = fopen("borrow", "w");
    if (borrow_file != NULL) {
        borrow_s *cur_borrow = borrow_head;
        while (cur_borrow != NULL) {
            fprintf(borrow_file, "%d | %d | %ld | %ld\n",
                    cur_borrow->studentnum, cur_borrow->booknum,
                    cur_borrow->borrowdate, cur_borrow->returndate);
            cur_borrow = cur_borrow->next;
        }
        fclose(borrow_file);
    }
}


int main() {
    get_client();    
    get_book();
    get_borrow();
    sort_clients();
    save_all_data();
    sort_books();
    save_all_data();
        
    do {
        libservice();
    } while(loop_main);	

    return 0;
}
