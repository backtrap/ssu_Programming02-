#include <stdio.h>
#include <stdlib.h>


#define N 100

struct linked_list {
	char d;
	struct linked_list *next;
};

typedef struct linked_list ELEMENT;

typedef ELEMENT *LINK;

LINK string_to_list(char s[]) {
	#include <string.h>

	LINK head;
	LINK tail;
	LINK temp;
	int length = strlen(s);
	
	if (s[0] == '\n')
		return NULL;

	head = malloc(sizeof(ELEMENT));
	head->d = s[0];
	head->next = NULL;
	tail = head;

	for (int i = 1; i < length; i++) {
		temp = malloc(sizeof(ELEMENT));
		temp->d = s[i];
		tail->next = temp;
		tail = temp;
	}

	return head;
}

void print_list(LINK head) {
	if (head == NULL)
		printf("NULL \n");
	else {
		printf("%c --> ", head -> d);
		print_list(head -> next);
	}
}

int main(void) {
	char input[N];
	LINK h;

	printf("문자열 입력: ");
	scanf("%s", input);

	h = string_to_list(input);
	
	printf("변환 리스트 결과 : \n");

	print_list(h);
	printf("\n\n");

	return 0;
}
