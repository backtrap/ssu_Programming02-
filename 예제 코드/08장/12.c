#include <stdio.h>
#include <stdbool.h>

#define DOLLAR true
#define WON false

typedef struct new_product {
	char * name;
	bool w_d;

	union {
		int won;
		float dollar;
	};
} new_product;

int main() {
	int i;
	new_product item[2];
	item[0].name = "PMP";
	item[0].won = 500000;
	item[0].w_d = WON;
	item[1].name = "CAMER";
	item[1].dollar = 799.95;
	item[1].w_d = DOLLAR;

	for (i = 0; i < 2; i++) {
		printf("품명 : %-10s", item[i].name);
		
		if (item[i].w_d)
			printf("가격 : $%11.2f\n", item[i].dollar);
		else
			printf("가격 : %12d 원\n", item[i].won);
	}

	return 0;
}

