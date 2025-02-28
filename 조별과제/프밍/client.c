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
	int find = 0;
	int x = 0;
	int y = 0;
	char avail;

	// extern book_s *book_head;
	book_s * i;
	book_s *p = NULL;
	for (i = book_head; i != NULL; i = i->next) {
		if (strcmp(input, i->bookname) == 0) {
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
printf("%s", p->bookname);

	return ;
}


// 회원용 출판사로 검색
void searchPublisher(void) {
	char input[100];
	printf("\n\n");
	printf("출판사를 입력하세요: ");
	getchar();
	scanf("%[^\n]", input);
	int find = 0;
	int x = 0;
	int y = 0;

	// extern book_s *book_head;
	book_s * i;
	for (i = book_head; i != NULL; i = i->next) {
		if (strcmp(input, i->publisher) == 0) {
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
	
// 회원용 ISBN으로 검색
void searchISBN(void) {
	long long input;
	printf("\n\n");
	printf("ISBN을 입력하세요: ");
	scanf("%lld", &input);
	int find = 0;
	int x = 0;
	int y = 0;

	// extern book_s *book_head;
	book_s * i;
	for (i = book_head; i != NULL; i = i->next) {
		if (input == i->ISBN) {
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


// 회원용 저자명으로 검색
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


// 회원용 책 전체 검색
void searchAll(void) {
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

			printf("도서번호: %d\n", i->booknum);
			printf("도서명: %s\n", j->bookname);
			printf("대여일자:\n"); // 구조체 수정 후 추가
			printf("반납일자:\n"); // 구조체 수정 후 추가
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
		printf("2. 이름\n");
		printf("3. 주소\n");
		printf("4. 전화번호\n");

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
			printf("이름을 입력해주세요:");
			scanf("%s", input);
			strcpy(i->name, input);
			break;
		case 3 :
			printf("주소를 입력해주세요:");
			getchar();
			scanf("%[^\n]", input);
			strcpy(i->address, input);
			break;
		case 4 :
			printf("전화번호를 입력해주세요:");
			scanf("%s", input);
			strcpy(i->phonenum, input);
			break;
	}

	return ;
}

void withdraw(int id) {
	// extern client_s *client_head;
	int count = 0;
	int loop_withdraw = 0;
	client_s *i = NULL;
	client_s *prev = client_head;

	if (client_head->studentnum == id) {
		client_s * temp = malloc(sizeof(client_s));
		temp = client_head;
		client_head = client_head->next;
		free(temp);

		printf("회원 탈퇴가 완료되었습니다.\n");
		sort_clients();

		loop_withdraw = 0;

		return ;
	}
	else {
		for (i = client_head; i->studentnum == id; i = i->next) 
			count++;
	
		for (int j = 0; j < count - 1; j++) 
			prev = prev->next;

		client_s * temp = malloc(sizeof(client_s));
		temp = prev->next;
		prev = temp->next;
		free(temp);
		
		printf("회원 탈퇴가 완료되었습니다.\n");
		sort_clients();

		loop_withdraw = 0;

		return ;
	}
}



