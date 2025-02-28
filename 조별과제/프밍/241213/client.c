#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "user.h"

// extern char logname[15];

void client_func(int id);

void searchBook(void);

void searchTitle(void);
void searchPublisher(void);
void searchISBN(void);
void searchAuthor(void);
void searchAll(void);

void myBook(int id);
void edit(int id);
void withdraw(int id);
void logout(int id); // 함수로 구현 x
void finish(void); // 함수로 구현 x
void printBook(char title[]);

// 회원용 기본 메뉴
void client_func(int id) {
	int myId = id;
	int loop_client = 1;
	int choice;

	do {
		printf("\n\n");
		printf(">> 회원 메뉴 <<\n");
		printf("1. 도서  검색		2. 내 대여 목록\n");
		printf("3. 개인 정보 수정	4. 회원 탈퇴\n");
		printf("5. 로그아웃		6. 프로그램 종료\n");
		printf("번호를 선택하세요: ");

		scanf("%d", &choice);
		if (choice < 1 || choice > 6) {
			printf("1 ~ 6 사이의 버튼을 눌러주세요.\n");
			continue;
		}

		switch (choice) {
			case 1 :
				searchBook();
				break;
			case 2 :
				myBook(myId);
				break;
			case 3 :
				edit(myId);
				break;
			case 4 : 
				withdraw(myId);
				return ;
				break;
			case 5 :
				loop_client = 0;
				printf("\n\n");
				return ;
				break;
			case 6 :
				loop_client = 0;
				loop_main = 0;
				break;
		}
	} while (loop_client);

	return ;
}

// 회원용 책 검색
void searchBook(void) {
	int loop_searchBook = 1;
	int loop_choice = 1;

	while(loop_searchBook) {
		printf("\n\n");
		printf(">> 도서 검색 <<\n");
		printf("1. 도서명 검색		2. 출판사 검색\n");
		printf("3. ISBN 검색		4. 저자명 검색\n");
		printf("5. 전체 검색		6. 이전 메뉴\n");
		printf("번호를 선택하세요: ");

		int choice;
		scanf("%d", &choice);
		if (choice < 1 || choice > 6) {
			printf("1~6 사이의 번호를 입력해주세요.\n");
			continue;
		}
		
		switch (choice) {
			case 1 :
				searchTitle();
				break;
			case 2 :
				searchPublisher();
				break;
			case 3 :
				searchISBN();
				break;
			case 4 :
				searchAuthor();
				break;
			case 5 :
				searchAll();
				break;
			case 6 :
				loop_choice = 0;
				return ;
		}
	} 

	return ;
}

// 회원용 제목으로 검색
void searchTitle(void) {
	char input[100];
	printf("\n\n");
	printf("도서명을 입력하세요: ");
	getchar();
	scanf("%[^\n]", input);
	
	printBook(input);

	return ;
}


// 회원용 출판사로 검색
void searchPublisher(void) {
    char input[100];
    printf("\n\n");
    printf("출판사를 입력하세요: ");
    getchar();
    scanf("%[^\n]", input);

    char Title[N][30]; // 출판사 저장할 배열
    book_s *i;
    int count = 0;

    // 출판사 이름을 배열에 저장
    for (i = book_head; i != NULL; i = i->next) {
        if (strcmp(i->publisher, input) == 0) {// 출판사 이름이 입력된 문자열과 매칭될 때 
            strcpy(Title[count++], i->bookname);
	// printf("%s\n", i->bookname);
    }
}

    // 중복 제거
    for (int i1 = 0; i1 < count; i1++) {
        for (int i2 = i1 + 1; i2 < count; i2++) {
            if (strcmp(Title[i1], Title[i2]) == 0) {
                // 중복 제거: 요소를 밀어서 제거
                for (int k = i2; k < count - 1; k++) {
                    strcpy(Title[k], Title[k + 1]);
                }
                count--; // 요소 개수를 하나 줄임
                i2--;    // 루프 인덱스를 조정
            }
        }
    }

    // 중복 제거 후 결과 출력
    for (int i1 = 0; i1 < count; i1++) {
        printBook(Title[i1]);
    }

    return;
}


	
// 회원용 ISBN으로 검색
void searchISBN(void) {
	long long input;
	printf("\n\n");
	printf("ISBN을 입력하세요: ");
	scanf("%lld", &input);
	
	// extern book_s *book_head;
	book_s * i;
	book_s * j;
	for (i = book_head; i != NULL; i = i->next) {
		if (input == i->ISBN) {
			j = i;
		}
	}

	printBook(j->bookname);

	return ;
}


// 회원용 저자명으로 검색
void searchAuthor(void) {
	char input[100];
    printf("\n\n");
    printf("저자명을 입력하세요: ");
    getchar();
    scanf("%[^\n]", input);

    char Title[N][30]; // 출판사 저장할 배열
    book_s *i;
    int count = 0;

    // 출판사 이름을 배열에 저장
    for (i = book_head; i != NULL; i = i->next) {
        if (strcmp(i->author, input) == 0) {// 출판사 이름이 입력된 문자열과 매칭될 때 
            strcpy(Title[count++], i->bookname);
    }
}

    // 중복 제거
    for (int i1 = 0; i1 < count; i1++) {
        for (int i2 = i1 + 1; i2 < count; i2++) {
            if (strcmp(Title[i1], Title[i2]) == 0) {
                // 중복 제거: 요소를 밀어서 제거
                for (int k = i2; k < count - 1; k++) {
                    strcpy(Title[k], Title[k + 1]);
                }
                count--; // 요소 개수를 하나 줄임
                i2--;    // 루프 인덱스를 조정
            }
        }
    }

    // 중복 제거 후 결과 출력
    for (int i1 = 0; i1 < count; i1++) {
        printBook(Title[i1]);
    }

    return;
}


// 회원용 저자명으로 검색
/*
void searchAuthor(void) {
	char input[100];
	printf("\n\n");
	printf("저자를 입력하세요: ");
	getchar();
	scanf("%[^\n]", input);
	int find = 0;
	int x = 0;
	int y = 0;

	// extern book_s *book_head;
	book_s * i;
	for (i = book_head; i != NULL; i = i->next) {
		if (strcmp(input, i->author) == 0) {
			// y++;
			// if (i->available == 'Y')
				// x++;

			printf("도서명: %s\n", i->bookname);
			printf("출판사: %s\n", i->publisher);
			printf("저자명: %s\n", i->author);
			printf("ISBN: %lld\n", i->ISBN);
			printf("소장처: %s\n", i->location);
			printf("대여가능 여부: %c(%d/%d)\n", i->available, x, y); // (%d/%d) 필요
			printf("** Y는 대여가능, N은 대여불가를 의미\n");
			printf("** (x/y) : (대여된 총 권수 / 보유하고 있는 총 권수\n\n");

			find = 1;
		}
	}

	if (find == 0)
		printf("해당 책은 없습니다.\n");

	return ;
}
*/


// 회원용 책 전체 검색
void searchAll(void) {
    char Title[N][30];
    book_s *i;
    int count = 0;

    // 모든 책 이름을 Title 배열에 복사
    for (i = book_head; i != NULL; i = i->next)
        strcpy(Title[count++], i->bookname);

    // 중복 제거
    for (int i1 = 0; i1 < count; i1++) {
        for (int i2 = i1 + 1; i2 < count; i2++) {
            if (strcmp(Title[i1], Title[i2]) == 0) {
                // 중복된 요소를 제거하기 위해 Title[i2]를 Title[i2+1]로 덮어쓰기
                for (int k = i2; k < count - 1; k++) {
                    strcpy(Title[k], Title[k + 1]);
                }
                count--; // 총 개수를 줄임
                i2--;    // 한 단계 뒤로 가서 새로 덮어쓴 값을 확인
            }
        }
    }

    // 중복 제거 후 결과 출력
    for (int i1 = 0; i1 < count; i1++)
        printBook(Title[i1]);

    return;
}





// 회원용 책 전체 검색
/* void searchAll(void) {
	// extern book_s *book_head;
	printf("\n\n");
	book_s * i;

	for (i = book_head; i != NULL; i = i->next) {
		printf("도서명: %s\n", i->bookname);
		printf("출판사: %s\n", i->publisher);
		printf("저자명: %s\n", i->author);
		printf("ISBN: %lld\n", i->ISBN);
		printf("소장처: %s\n", i->location);
		printf("대여가능 여부: %c\n", i->available); // (%d/%d) 필요
		// printf("** Y는 대여가능, N은 대여불가를 의미\n");
		// printf("** (x/y) : (대여된 총 권수 / 보유하고 있는 총 권수\n\n");
		printf("\n\n");
	}		

	return ;
}
*/

// 회원용 내 대여 목록
void myBook(int id) {
	int myId = id;
	borrow_s *i;
	// extern borrow_s *borrow_head;
	// extern book_s *book_head;
	int find = 0;
	
	for (i = borrow_head; i != NULL; i = i->next) {
		if (myId == i->studentnum) {
			book_s *j = book_head;
			while (i->booknum != j->booknum)
				j = j->next;

			char get_book[100];
			char return_book[100];
			format_date_korean(i->borrowdate, get_book, sizeof(get_book));
printf("%s", get_book);
			format_date_korean(i->returndate, return_book, sizeof(return_book));

			printf("도서번호: %d\n", i->booknum);
			printf("도서명: %s\n", j->bookname);
			printf("대여일자: %s\n", get_book); // 구조체 수정 후 추가
			printf("반납일자:%s\n", return_book); // 구조체 수정 후 추가
			printf("\n");

			find = 1;
		}
	}

	if (find == 0) {
		printf("\n\n");
		printf("대여하신 책이 없습니다.\n");
	}

	return ;
}


// 회원용 정보 수정
void edit(int id) {
	// extern client_s *client_head;
	int choice;
	char input[100];
	int loop_edit = 1;

	client_s *i;
	for (i = client_head; i != NULL; i = i->next) {
		if (id == i->studentnum)
			break;
	}

	do {
		printf("\n\n");
		printf("수정할 항목을 선택하세요.\n");
		printf("1. 비밀번호\n");
		// printf("2. 이름\n");
		printf("2. 주소\n");
		printf("3. 전화번호\n");

		scanf("%d", &choice);
		if (choice < 1 || choice > 4) {
			printf("번호를 다시 입력해주세요. 1~4의 번호를 입력해야 됩니다.\n");
		}
		else
			loop_edit = 0;
	} while(loop_edit);

	switch (choice) {
		case 1 :
			printf("비밀번호를 입력해주세요:");
			scanf("%s", input);
			strcpy(i->password, input);
			break;
		case 2 :
			printf("주소를 입력해주세요:");
			getchar();
			scanf("%[^\n]", input);
			strcpy(i->address, input);
			break;
		case 3 :
			printf("전화번호를 입력해주세요:");
			scanf("%s", input);
			strcpy(i->phonenum, input);
			break;
	}

	return ;
}

// 회원 탈퇴 함수
void withdraw(int id) {
    int myId = id;
    client_s *current = client_head;
    client_s *previous = NULL;
    borrow_s * i;
   
	for (i = borrow_head; i != NULL; i = i->next) {
		if (myId == i->studentnum) {
			printf("대여 중인 책이 있으므로 회원탈퇴를 할 수 없습니다.\n\n\n");
			return ;
		}
	}

    // 연결 리스트 순회
    while (current != NULL) {
        if (current->studentnum == id) { // ID가 일치하는 회원 찾기
            if (previous == NULL) {
                // 첫 번째 노드를 삭제하는 경우
                client_head = current->next;
            } else {
                // 중간 또는 마지막 노드를 삭제하는 경우
                previous->next = current->next;
            }

            // 메모리 해제
            free(current);
            printf("회원 ID %d의 계정이 성공적으로 삭제되었습니다.\n\n", id);
	// 회원탈퇴 확인용 코드
	/*
	current = client_head;
	while(current != NULL) {
		printf("%s\n\n", current->name);
		current = current->next;
	}
	*/
            return;
        }

        // 다음 노드로 이동
        previous = current;
        current = current->next;
    }

    // ID를 찾지 못한 경우
    printf("회원 ID %d를 찾을 수 없습니다.\n", id);
}


// 책 출력 함수
void printBook(char title[]) {
	int find = 0;
	int x = 0;
	int y = 0;
	char avail;

	// extern book_s *book_head;
	book_s * i;
	book_s *p = NULL;
	for (i = book_head; i != NULL; i = i->next) {
		if (strcmp(title, i->bookname) == 0) {
			y++;
			if (i->available == 'N')
				x++;

			p = i;
			find = 1;		
		}
	}

	if (x == y)
		avail = 'N';
	else
		avail = 'Y';

	if (find == 1) {
		printf("도서명: %s\n", p->bookname);
		printf("출판사: %s\n", p->publisher);
		printf("저자명: %s\n", p->author);
		printf("ISBN: %lld\n", p->ISBN);
		printf("소장처: %s\n", p->location);
				printf("대여가능 여부: %c(%d/%d)\n", avail, x, y); // (%d/%d) 필요
		printf("** Y는 대여가능, N은 대여불가를 의미\n");
		printf("** (x/y) : (대여된 총 권수 / 보유하고 있는 총 권수\n\n");
	}
	else
		printf("해당 책은 없습니다.\n");

	return ;
}
