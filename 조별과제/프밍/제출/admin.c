#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "user.h"

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
            save_all_data();
        } else if (strcmp(adminInput, "2") == 0) {
            delete_book();
            save_all_data();
        } else if (strcmp(adminInput, "3") == 0) {
            borrow_book();
            save_all_data();
        } else if (strcmp(adminInput, "4") == 0) {
            return_book();
            save_all_data();
        } else if (strcmp(adminInput, "5") == 0) {
            search_books();
        } else if (strcmp(adminInput, "6") == 0) {
            list_clients();
        } else if (strcmp(adminInput, "7") == 0) {
            printf("관리자 로그아웃\n");
            return;
        } else if (strcmp(adminInput, "8") == 0) {
            printf("프로그램 종료\n");
            exit(0);
        } else {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
}

void register_book() {
    printf(">> 도서 등록 <<\n");

    // 새 도서 정보 입력 받기
    book_s *new_book = (book_s *)malloc(sizeof(book_s));
    if (new_book == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }
    getchar();

    printf("도서명: ");
    scanf("%[^\n]", new_book->bookname);
    getchar();

    printf("출판사: ");
    scanf("%[^\n]", new_book->publisher);
    getchar();

    printf("저자: ");
    scanf("%[^\n]", new_book->author);
    getchar();

    printf("ISBN: ");
    scanf("%lld", &new_book->ISBN);
    getchar();

    printf("소장처: ");
    scanf("%[^\n]", new_book->location);

    // 자동 입력
    new_book->available = 'Y';

    // 도서 번호 자동 생성: 연결 리스트를 처음부터 끝까지 순회하며 가장 마지막 번호를 찾음
    int last_booknum = 0; // 초기 도서 번호 시작값
    book_s *cur = book_head;
    while (cur != NULL) {
	if (cur->booknum > last_booknum)
	            last_booknum = cur->booknum; // 마지막 도서 번호를 업데이트
	// 도서번호 확인용 코드
            // printf("\n%d\n", last_booknum);
	cur = cur->next;
    }
    last_booknum++; // 마지막 번호에서 +1
    new_book->booknum = last_booknum;

    printf("\n도서번호: %d, 대여 가능 여부: %c\n", new_book->booknum, new_book->available);

    char confirm;
    printf("등록하시겠습니까? (Y/N): ");
    scanf(" %c", &confirm);

    if (confirm != 'Y' && confirm != 'y') {
        printf("등록이 취소되었습니다.\n");
        free(new_book);
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

    printf("도서가 성공적으로 등록되었습니다.\n");
}


void delete_book() {
    int deleteNum;
    book_s *cur = book_head, *prev = NULL;

    printf("삭제할 도서 번호를 입력하세요: ");
    scanf("%d", &deleteNum);

    while (cur != NULL) {
        if (cur->booknum == deleteNum) {
            if (cur->available == 'Y') {
                if (prev == NULL) {
                    book_head = cur->next;
                } else {
                    prev->next = cur->next;
                }
                free(cur);
                printf("도서가 성공적으로 삭제되었습니다.\n");
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

void borrow_book() {
    int book_num, student_num;
    char confirm;
    book_s *book_cur = book_head;
    client_s *client_cur = client_head;
    borrow_s *new_borrow = (borrow_s *)malloc(sizeof(borrow_s));

    if (new_borrow == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }

    printf("대여할 도서번호를 입력하세요: ");
    scanf("%d", &book_num);

    while (book_cur != NULL) {
        if (book_cur->booknum == book_num && book_cur->available == 'Y') {
            break;
        }
        book_cur = book_cur->next;
    }

    if (book_cur == NULL) {
        printf("대여 가능한 도서를 찾을 수 없습니다.\n");
        free(new_borrow);
        return;
    }

    printf("학번을 입력하세요: ");
    scanf("%d", &student_num);

    while (client_cur != NULL) {
        if (client_cur->studentnum == student_num) {
            printf("학생명: %s\n", client_cur->name);
            break;
        }
        client_cur = client_cur->next;
    }

    if (client_cur == NULL) {
        printf("회원 정보를 찾을 수 없습니다.\n");
        free(new_borrow);
        return;
    }

    printf("이 도서를 대여하시겠습니까? (Y/N): ");
    scanf(" %c", &confirm);

    if (confirm == 'Y' || confirm == 'y') {
        new_borrow->studentnum = student_num;
        new_borrow->booknum = book_num;
        new_borrow->borrowdate = time(NULL);

        struct tm *tm_info = localtime(&new_borrow->borrowdate);
        tm_info->tm_mday += 30;
        new_borrow->returndate = mktime(tm_info);

        new_borrow->next = borrow_head;
        borrow_head = new_borrow;

        book_cur->available = 'N';

        printf("도서가 대여되었습니다.\n");
    } else {
        free(new_borrow);
        printf("대여가 취소되었습니다.\n");
    }
}

// 한글 요일을 반환하는 함수
const char* get_korean_weekday(int wday) {
    const char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    return weekdays[wday];
}

// 날짜를 "YYYY년 MM월 DD일 요일" 형식으로 반환하는 함수
void format_date_korean(time_t time, char *formatted_date, size_t size) {
    struct tm *tm_info = localtime(&time);

    char date_part[64];
    strftime(date_part, sizeof(date_part), "%Y년 %m월 %d일", tm_info);

    snprintf(formatted_date, size, "%s %s", date_part, get_korean_weekday(tm_info->tm_wday));
}

// 예제: 반납 예정일 출력 수정
void print_return_date(time_t borrowdate) {
   struct tm *tm_info = localtime(&borrowdate);

    // 기본적으로 30일 추가
    tm_info->tm_mday += 30;

    // 정규화
    mktime(tm_info);

    // 30일째 되는 날이 일요일인지 확인
    if (tm_info->tm_wday == 0) {  // 일요일인 경우
        tm_info->tm_mday += 1;   // 하루 추가
        mktime(tm_info);         // 정규화
    }

    printf("반납 예정일: %d년 %d월 %d일 %s\n",
           tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday, get_korean_weekday(tm_info->tm_wday));
}

// 예제 함수: 반납 처리 로직에서 날짜 출력
void return_book() {
    int student_num, book_num;
    borrow_s *cur_borrow = borrow_head;
    borrow_s *prev_borrow = NULL;
    book_s *cur_book = book_head;
    char confirm;

    printf(">> 도서 반납 <<\n");

    printf("학번을 입력하세요: ");
    scanf("%d", &student_num);

    printf("\n>> 회원의 대여 목록 <<\n");
    int has_borrowed_books = 0;
    borrow_s *temp_borrow = borrow_head;

    while (temp_borrow != NULL) {
        if (temp_borrow->studentnum == student_num) {
            book_s *borrowed_book = book_head;
            while (borrowed_book != NULL) {
                if (borrowed_book->booknum == temp_borrow->booknum) {
                    char borrow_date[100], return_date[100];
                    format_date_korean(temp_borrow->borrowdate, borrow_date, sizeof(borrow_date));
                    format_date_korean(temp_borrow->returndate, return_date, sizeof(return_date));

                    printf("도서번호: %d\n도서명: %s\n대여일자: %s\n반납예정일: %s\n\n",
                           borrowed_book->booknum,
                           borrowed_book->bookname,
                           borrow_date,
                           return_date);
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

    printf("반납할 도서번호를 입력하세요: ");
    scanf("%d", &book_num);

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

    printf("도서 반납처리를 할까요? (Y/N): ");
    scanf(" %c", &confirm);

    if (confirm == 'Y' || confirm == 'y') {
        if (prev_borrow == NULL) {
            borrow_head = cur_borrow->next;
        } else {
            prev_borrow->next = cur_borrow->next;
        }

        cur_book = book_head;
        while (cur_book != NULL) {
            if (cur_book->booknum == book_num) {
                cur_book->available = 'Y';
                break;
            }
            cur_book = cur_book->next;
        }

        printf("도서가 반납되었습니다.\n");
        free(cur_borrow);
    } else {
        printf("반납이 취소되었습니다.\n");
    }
}


void search_books() {
    searchBook();
}

void list_clients() {
    int input;
    char name[20];
    int studentnum;

    printf(">> 회원 목록 <<\n");

    do {
        client_s *cur = client_head;
        printf("\n1. 이름 검색    2. 학번 검색\n");
        printf("3. 전체 검색    4. 이전 메뉴\n");
        printf("번호를 선택하세요: ");
        scanf("%d", &input);

        if (input == 1) { // 이름 검색
            printf("이름을 입력하세요: ");
            scanf("%s", name);
            int found = 0;
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
            int found = 0;
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
    } while (input != 4);
}