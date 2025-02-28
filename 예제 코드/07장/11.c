#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50
#define L 10

int input_words(char * []);
int comp_voca(const void *, const void *);
void print_words(int, char * []);

int main() {
	char * words_p[N];
	int num_word = 0;

	num_word = input_words(words_p);
	qsort(words_p, num_word, sizeof(char *), comp_voca);
	print_words(num_word, words_p);

	for (int i = 0; i < num_word; i++) 
		free(words_p[i]);

	return 0;
}

int input_words(char * words[]) {
	int num = 0;
	char temp[100];

	while (1) {
		printf("단어를 입력하세요 : ");
		scanf("%[^\n]", temp);
		getchar();

		if (strcmp(temp, ".end") == 0)
			break;
		if (strlen(temp) < 9) {
			words[num] = (char *) calloc(strlen(temp) + 1, sizeof(char));
			strcpy(words[num], temp);
		}
		else
			continue;

		if (++num == N)
			break;
	}

	return num;
}

int comp_voca(const void *p, const void *q) {
	return strcmp(*(char **)p, *(char **)q);
}

void print_words(int num, char * words[]) {
	int i;

	for (i = 0; i < num; i++) 
		printf("%s\n", words[i]);
}

