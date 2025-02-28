#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "user.h"

// 확장 함수: 문자열 입력 처리 (개행 문자 제거)
void read_line(char *buffer, size_t size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // 개행 문자 제거
}

void admin_func() {
    char adminInput[10];
    while (1) {
        printf(">> 관리자 메뉴 <<\n");
        printf("1. 도서 등록        2. 도서 삭제        3. 도서 대여        4. 도서 반납\n");
        printf("5. 도서 검색        6. 회원 목록        7. 로그아웃         8. 프로그램 종료\n");
        printf("번호를 선택하세요: ");
        scanf("%s", adminInput);

        if (strcmp(adminInput, "1") == 0) {
            register_book();
        } else if (strcmp(adminInput, "2") == 0) {
            delete_book();
        } else if (strcmp(adminInput, "3") == 0) {
            borrow_book();
        } else if (strcmp(adminInput, "4") == 0) {
            return_book();
        } else if (strcmp(adminInput, "5") == 0) {
            search_books();
        } else if (strcmp(adminInput, "6") == 0) {
            list_clients();
        } else if (strcmp(adminInput, "7") == 0) {
            printf("관리자 로그아웃\n");
            // 다시 메인 화면으로 돌아가기
            save_all_data();
            break;
        } else if (strcmp(adminInput, "8") == 0) {
            printf("프로그램 종료\n");
            save_all_data();
            break;
            
            exit(0);
        } else {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
}

// 관리자 기능 함수

// 1. 도서 등록(완료)
void register_book() {
    printf(">> 도서 등록 <<\n");
    get_book(); // 기존 도서 정보 불러오기

    // 새 도서 정보 입력 받기
    book_s *new_book = (book_s *)malloc(sizeof(book_s));
    if (new_book == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }
    getchar();
    // 도서명 입력
    printf("도서명: ");
    read_line(new_book->bookname, sizeof(new_book->bookname));

    // 출판사 입력
    printf("출판사: ");
    read_line(new_book->publisher, sizeof(new_book->publisher));

    // 저자 입력
    printf("저자: ");
    read_line(new_book->author, sizeof(new_book->author));

    // ISBN 입력
    printf("ISBN: ");
    scanf("%lld", &new_book->ISBN);
    getchar(); // 입력 버퍼 비우기

    // 소장 위치 입력
    printf("소장처: ");
    read_line(new_book->location, sizeof(new_book->location));

    // 자동 입력 사항 출력
    printf("\n자동입력 사항\n");

    // 대여 가능 여부
    new_book->available = 'Y';
    printf("대여 가능한 여부: %c\n", new_book->available);

      // 도서 번호 자동 생성: 연결 리스트에서 마지막 도서 번호를 가져와 +1
    if (book_head == NULL) {
        new_book->booknum = 1000000; // 리스트가 비어있으면 초기값 설정
    } else {
        book_s *cur = book_head;
        while (cur->next != NULL) {
            cur = cur->next; // 마지막 노드로 이동
        }
        new_book->booknum = cur->booknum + 1; // 마지막 번호에서 +1
    }
    printf("도서번호: %d\n", new_book->booknum);

    // 등록 확인
    char confirm;
    printf("\n등록하시겠습니까? (Y/N): ");
    scanf(" %c", &confirm);
    if (confirm != 'Y' && confirm != 'y') {
        printf("등록이 취소되었습니다.\n");
        free(new_book); // 메모리 해제
        return;
    }

    // 연결 리스트에 새 도서 추가
    new_book->next = NULL;
    if (book_head == NULL) {
        book_head = new_book; // 리스트가 비어 있으면 첫 노드로 설정
    } else {
        book_s *cur = book_head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_book; // 리스트 끝에 새 노드 추가
    }

    // 도서 정보를 파일에 저장
    FILE *book_file = fopen("book", "a");
    if (book_file == NULL) {
        printf("도서 파일을 열 수 없습니다.\n");
        return;
    }

    fprintf(book_file, "%d | %s | %s | %s | %lld | %s | %c\n",
            new_book->booknum,
            new_book->bookname,
            new_book->publisher,
            new_book->author,
            new_book->ISBN,
            new_book->location,
            new_book->available);

    fclose(book_file);

    printf("도서가 성공적으로 등록되었습니다.\n");
}

// 도서 삭제(완료)
void delete_book() {
    int inputNum;
    char inputSearch[30];
    book_s *cur = book_head;
    book_s *prev = NULL;

    printf(">> 도서 삭제 <<\n");
    printf("1. 도서명 검색   2. ISBN 검색\n");
    printf("검색 번호를 선택하세요: ");
    scanf("%d", &inputNum);
    getchar(); // 입력 버퍼 비우기

    if (inputNum == 1) {
        printf("도서명을 입력하세요: ");
        read_line(inputSearch, sizeof(inputSearch));

        printf("\n>> 검색 결과 <<\n");
        while (cur != NULL) {
            if (strcmp(cur->bookname, inputSearch) == 0) {
                printf("도서번호: %d (삭제 가능 여부: %c)\n도서명: %s\n출판사: %s\n저자명: %s\nISBN: %lld\n소장처: %s\n\n",
                       cur->booknum, cur->available, cur->bookname, cur->publisher, cur->author, cur->ISBN, cur->location);
            }
            cur = cur->next;
        }
    } else if (inputNum == 2) {
        printf("ISBN을 입력하세요: ");
        read_line(inputSearch, sizeof(inputSearch));

        printf("\n>> 검색 결과 <<\n");
        while (cur != NULL) {
            if (cur->ISBN == atoll(inputSearch)) {
                printf("도서번호: %d (삭제 가능 여부: %c)\n도서명: %s\n출판사: %s\n저자명: %s\nISBN: %lld\n소장처: %s\n\n",
                       cur->booknum, cur->available, cur->bookname, cur->publisher, cur->author, cur->ISBN, cur->location);
            }
            cur = cur->next;
        }
    } else {
        printf("잘못된 입력입니다. 다시 시도하세요.\n");
        return;
    }

    // 도서 삭제 진행
    printf("삭제할 도서의 번호를 입력하세요: ");
    int deleteNum;
    scanf("%d", &deleteNum);

    cur = book_head; // 다시 처음부터 검색
    while (cur != NULL) {
        if (cur->booknum == deleteNum) {
            if (cur->available == 'Y') {
                // 삭제 처리
                if (prev == NULL) { // 첫 번째 노드 삭제
                    book_head = cur->next;
                } else {
                    prev->next = cur->next;
                }
                free(cur);

                printf("도서가 성공적으로 삭제되었습니다.\n");

                // 파일 업데이트
                FILE *book_file = fopen("book", "w");
                if (book_file == NULL) {
                    printf("도서 파일을 열 수 없습니다.\n");
                    return;
                }

                book_s *temp = book_head;
                while (temp != NULL) {
                    fprintf(book_file, "%d | %s | %s | %s | %lld | %s | %c\n",
                            temp->booknum,
                            temp->bookname,
                            temp->publisher,
                            temp->author,
                            temp->ISBN,
                            temp->location,
                            temp->available);
                    temp = temp->next;
                }

                fclose(book_file);
                return;
            } else {
                printf("이 도서는 삭제할 수 없습니다.\n");
                return;
            }
        }
        prev = cur;
        cur = cur->next;
    }

    printf("해당 도서를 찾을 수 없습니다.\n");
}


// 도서 대여 (완료)
void borrow_book() {
    int inputNum;
    char inputSearch[30];
    book_s *book_cur = book_head;
    client_s *client_cur = client_head;
    borrow_s *new_borrow = (borrow_s *)malloc(sizeof(borrow_s));

    if (new_borrow == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }

    printf(">> 도서 대여 <<\n");
    printf("1. 도서명 검색   2. ISBN 검색\n");
    printf("검색 번호를 선택하세요: ");
    scanf("%d", &inputNum);
    getchar(); // 입력 버퍼 비우기

    // 검색 및 결과 출력
    if (inputNum == 1) {
        printf("도서명을 입력하세요: ");
        read_line(inputSearch, sizeof(inputSearch));

        printf("\n>> 검색 결과 <<\n");
        while (book_cur != NULL) {
            if (strcmp(book_cur->bookname, inputSearch) == 0) {
                printf("도서번호: %d (대여 가능 여부: %c)\n도서명: %s\n출판사: %s\n저자명: %s\nISBN: %lld\n소장처: %s\n\n",
                       book_cur->booknum, book_cur->available, book_cur->bookname, book_cur->publisher, book_cur->author, book_cur->ISBN, book_cur->location);
            }
            book_cur = book_cur->next;
        }
    } else if (inputNum == 2) {
        printf("ISBN을 입력하세요: ");
        read_line(inputSearch, sizeof(inputSearch));

        printf("\n>> 검색 결과 <<\n");
        while (book_cur != NULL) {
            if (book_cur->ISBN == atoll(inputSearch)) {
                printf("도서번호: %d (대여 가능 여부: %c)\n도서명: %s\n출판사: %s\n저자명: %s\nISBN: %lld\n소장처: %s\n\n",
                       book_cur->booknum, book_cur->available, book_cur->bookname, book_cur->publisher, book_cur->author, book_cur->ISBN, book_cur->location);
            }
            book_cur = book_cur->next;
        }
    } else {
        printf("잘못된 입력입니다. 다시 시도하세요.\n");
        free(new_borrow);
        return;
    }

    book_cur = book_head; // 다시 처음부터 검색

    printf("대여 가능한 도서 목록에서 도서번호를 입력하세요: ");
    int book_num;
    scanf("%d", &book_num);
    getchar(); // 입력 버퍼 비우기

    while (book_cur != NULL) {
        if (book_cur->booknum == book_num) {
            if (book_cur->available == 'Y') {
                break;
            } else {
                printf("선택한 도서는 대여할 수 없습니다.\n");
                free(new_borrow);
                return;
            }
        }
        book_cur = book_cur->next;
    }

    if (book_cur == NULL) {
        printf("해당 도서번호의 도서를 찾을 수 없습니다.\n");
        free(new_borrow);
        return;
    }

    // 학생 정보 입력
    int student_num;
    printf("학번을 입력하세요: ");
    scanf("%d", &student_num);
    getchar(); // 입력 버퍼 비우기

    while (client_cur != NULL) {
        if (client_cur->studentnum == student_num) {
            printf("학생명: %s\n", client_cur->name);
            break;
        }
        client_cur = client_cur->next;
    }

    if (client_cur == NULL) {
        printf("학생 정보를 찾을 수 없습니다.\n");
        free(new_borrow);
        return;
    }

    // 대여 확인
    char confirm;
    printf("이 도서를 대여하시겠습니까? (Y/N): ");
    scanf(" %c", &confirm);
    getchar(); // 입력 버퍼 비우기

    if (confirm == 'Y' || confirm == 'y') {
        // 대여 정보 추가
        new_borrow->studentnum = student_num;
        new_borrow->booknum = book_num;
        new_borrow->borrowdate = time(NULL);

        // 반납 예정일 계산 (30일 후)
        struct tm *tm_info = localtime(&new_borrow->borrowdate);
        tm_info->tm_mday += 30;
        mktime(tm_info); // 날짜 계산
        new_borrow->returndate = mktime(tm_info);

        new_borrow->next = borrow_head;
        borrow_head = new_borrow;

        // 도서 상태 변경
        book_cur->available = 'N';

        // 파일 업데이트
        FILE *borrow_file = fopen("borrow", "a");
        if (borrow_file == NULL) {
            printf("대여 파일을 열 수 없습니다.\n");
            return;
        }

        char borrow_date[20], return_date[20];
        strftime(borrow_date, sizeof(borrow_date), "%Y-%m-%d", localtime(&new_borrow->borrowdate));
        strftime(return_date, sizeof(return_date), "%Y-%m-%d", localtime(&new_borrow->returndate));

        fprintf(borrow_file, "%d | %lld | %s | %s\n",
                student_num, book_cur->ISBN, borrow_date, return_date);
        fclose(borrow_file);

        // 도서 상태 파일 업데이트
        FILE *book_file = fopen("book", "w");
        if (book_file == NULL) {
            printf("도서 파일을 열 수 없습니다.\n");
            return;
        }

        book_s *cur = book_head;
        while (cur != NULL) {
            fprintf(book_file, "%d | %s | %s | %s | %lld | %s | %c\n",
                    cur->booknum, cur->bookname, cur->publisher, cur->author, cur->ISBN, cur->location, cur->available);
            cur = cur->next;
        }

        fclose(book_file);

        printf("도서가 대여되었습니다.\n");
    } else {
        free(new_borrow);
        printf("대여가 취소되었습니다.\n");
    }
}



void return_book() {
    int student_num, book_num;
    borrow_s *cur_borrow = borrow_head;
    borrow_s *prev_borrow = NULL;
    book_s *cur_book = book_head;
    char confirm;

    printf(">> 도서 반납 <<\n");

    // 학생 번호 입력
    printf("학번을 입력하세요: ");
    scanf("%d", &student_num);
    getchar(); // 입력 버퍼 비우기

    printf("\n>> 회원의 대여 목록 <<\n");

    // 학생의 대여 목록 출력
    int has_borrowed_books = 0; // 대여 기록 여부 확인
    borrow_s *temp_borrow = borrow_head;
    while (temp_borrow != NULL) {
        if (temp_borrow->studentnum == student_num) {
            // 대여 중인 도서를 찾기
            book_s *borrowed_book = book_head;
            while (borrowed_book != NULL) {
                if (borrowed_book->booknum == temp_borrow->booknum) {
                    // 대여 정보 출력
                    printf("도서번호: %d\n도서명: %s\n대여일자: %s반납예정일: %s\n\n",
                           borrowed_book->booknum,
                           borrowed_book->bookname,
                           ctime(&temp_borrow->borrowdate),
                           temp_borrow->returndate ? ctime(&temp_borrow->returndate) : "반납 전");
                    has_borrowed_books = 1;
                    break;
                }
                borrowed_book = borrowed_book->next;
            }
        }
        temp_borrow = temp_borrow->next;
    }

    if (!has_borrowed_books) {
        printf("대여 중인 도서가 없습니다.\n");
        return;
    }

    // 반납할 도서 번호 입력
    printf("반납할 도서번호를 입력하세요: ");
    scanf("%d", &book_num);
    getchar(); // 입력 버퍼 비우기

    // 대여 기록 찾기
    cur_borrow = borrow_head;
    while (cur_borrow != NULL) {
        if ((cur_borrow->studentnum == student_num) && (cur_borrow->booknum == book_num)) {
            break;
        }
        prev_borrow = cur_borrow;
        cur_borrow = cur_borrow->next;
    }

    if (cur_borrow == NULL) {
        printf("해당 도서의 대여 기록을 찾을 수 없습니다.\n");
        return;
    }

    // 반납 확인
    printf("도서 반납처리를 할까요? (Y/N): ");
    scanf(" %c", &confirm);
    getchar(); // 입력 버퍼 비우기

    if (confirm == 'Y' || confirm == 'y') {
        // 반납 처리: 대여 기록 삭제
        if (prev_borrow == NULL) {
            borrow_head = cur_borrow->next;
        } else {
            prev_borrow->next = cur_borrow->next;
        }

        // 도서를 대여 가능 상태로 변경
        cur_book = book_head;
        while (cur_book != NULL) {
            if (cur_book->booknum == book_num) {
                cur_book->available = 'Y';
                break;
            }
            cur_book = cur_book->next;
        }

        // 대여 기록 파일 갱신
        FILE *borrow_file = fopen("borrow", "w");
        if (borrow_file == NULL) {
            printf("대여 파일을 열 수 없습니다.\n");
            return;
        }

        borrow_s *temp_borrow = borrow_head;
        while (temp_borrow != NULL) {
            fprintf(borrow_file, "%d | %d | %ld | %ld\n",
                    temp_borrow->studentnum,
                    temp_borrow->booknum,
                    temp_borrow->borrowdate,
                    temp_borrow->returndate);
            temp_borrow = temp_borrow->next;
        }
        fclose(borrow_file);

        printf("도서가 반납되었습니다.\n");
        free(cur_borrow);
    } else {
        printf("반납이 취소되었습니다.\n");
    }
}


void search_books() {
    searchBook();
}

// 회원 검색 
void list_clients() {
    int input;
    char name[20];
    int studentnum;

    printf(">> 회원 목록 <<\n");

    do {
        client_s *cur = client_head; // 리스트의 시작 위치로 초기화
        printf("\n1. 이름 검색    2. 학번 검색\n");
        printf("3. 전체 검색    4. 이전 메뉴\n");
        printf("번호를 선택하세요: ");
        scanf("%d", &input);

        if (input == 1) { // 이름 검색
            printf("이름을 입력하세요: ");
            scanf("%s", name);
            int found = 0; // 검색 결과 확인용
            while (cur != NULL) {
                if (strcmp(cur->name, name) == 0) {
                    printf("학번: %d, 이름: %s, 주소: %s, 전화번호: %s\n",
                           cur->studentnum, cur->name, cur->address, cur->phonenum);
                    found = 1;
                }
                cur = cur->next;
            }
            if (!found) {
                printf("해당 이름의 회원을 찾을 수 없습니다.\n");
            }
        } else if (input == 2) { // 학번 검색
            printf("학번을 입력하세요: ");
            scanf("%d", &studentnum);
            int found = 0; // 검색 결과 확인용
            while (cur != NULL) {
                if (cur->studentnum == studentnum) {
                    printf("학번: %d, 이름: %s, 주소: %s, 전화번호: %s\n",
                           cur->studentnum, cur->name, cur->address, cur->phonenum);
                    found = 1;
                }
                cur = cur->next;
            }
            if (!found) {
                printf("해당 학번의 회원을 찾을 수 없습니다.\n");
            }
        } else if (input == 3) { // 전체 검색
            if (cur == NULL) {
                printf("등록된 회원이 없습니다.\n");
            }
            while (cur != NULL) {
                printf("학번: %d, 이름: %s, 주소: %s, 전화번호: %s\n",
                       cur->studentnum, cur->name, cur->address, cur->phonenum);
                cur = cur->next;
            }
        } else if (input == 4) { // 이전 메뉴
            printf("이전 메뉴로 돌아갑니다.\n");
        } else { // 잘못된 입력
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    } while (input != 4); // 4를 선택하면 루프 종료
}


void save_all_data() {
    // 정렬 데이터
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
