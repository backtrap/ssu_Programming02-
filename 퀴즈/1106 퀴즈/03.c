#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[100];
	int id;
	int age;
	int salary;
} employee;

int main() {
	FILE * f;
	char temp[200];
	employee * list = NULL;  
	int count = 0;

	f = fopen("./employee.txt", "w+");
	if (f == NULL) {
		printf("파일을 읽을 수 없습니다.\n");
		return 0;
	}

	list = (employee *)malloc(1 * sizeof(employee));
	if (list == NULL) {
		printf("메모리 할당 실패\n");
		fclose(f);
		return 0;
	}

	while (1) {
		printf("직원의 이름과 ID, 나이, 연봉을 입력해주세요 : ");
		printf("(종료를 원할 경우 'finish!'을 입력.)\n");

		fgets(temp, sizeof(temp), stdin);
		temp[strcspn(temp, "\n")] = 0;

		if (strcmp(temp, "finish!") == 0) {
			break;
		}

		sscanf(temp, "%s %d %d %d", (list + count)->name,
			   &((list + count)->id),
			   &((list + count)->age),
			   &((list + count)->salary));

		count++;

		list = (employee *)realloc(list, (count + 1) * sizeof(employee));
	}

	for (int i = 0; i < count; i++) {
		fprintf(f, "%s %d %d %d\n", (list + i)->name,
				(list + i)->id,
				(list + i)->age,
				(list + i)->salary);
	}

	fclose(f);
	free(list);

	return 0;
}
