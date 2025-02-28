#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	int department;
	int grade;
	char name[100];
	int salary;

} information;

int main() {
	FILE * fp;
	fp = fopen("./info.txt", "r");
	if (fp == NULL)
		return 0;
	
	int low = 0;
	int count = 0;
	char c;
	while((c = getc(fp)) != EOF) {
		count++;
		if (c == '\n')
			low++;
	}
	low++;
	
	char str[count];
	
	information arr[low];
	
	fseek(fp, 0, SEEK_SET);
	int i = 0;
	while((c = getc(fp)) != EOF)
		str[i++] = c;

	str[count] = '\0';

	char * str2[low];
printf("%s\n", str);
	for (int i = 0; i < count; i++) {
		if (str[i] == '\n') {
			str[i] = '&';
			
		}
	}

printf("\n%s\n", str);

	for (int i = 0; i < low; i++)
		sscanf(str, "%d %d %d %s %d ", &arr[i].id,
				&arr[i].department,
				&arr[i].grade,
				arr[i].name,
				&arr[i].salary);
	
	/* for (int i = 0; i < low; i++)
		printf("%d %d %d %s %d\n ", arr[i].id,
				arr[i].department,
				arr[i].grade,
				arr[i].name,
				arr[i].salary); */

	fclose(fp);

	return 0;
}

