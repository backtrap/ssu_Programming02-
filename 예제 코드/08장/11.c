#include <stdio.h>

#define WON 0
#define DOLLAR 1

typedef union won_or_dollar {
	int won;
	float dollar;
} won_or_dollar;

typedef struct product {
	char * name;
	_Bool w_d;
	won_or_dollar price;
} product;

int main() {
	int i;
	product item[2];
	item[0].name = "PMP";
	item[0].price.won = 500000;
	item[0].w_d = WON;
	item[1].name = "CAMERA";
	item[1].price.dollar = 799.95;
	item[1].w_d = DOLLAR;

	for (i = 0; i < 2; i++) {
		printf("품명 : %-10s", item[i].name);

		if (item[i].w_d)
			printf("가격 : $%11.2f\n", item[i].price.dollar);
		else
			printf("가격 : %12d 원\n", item[i].price.won);
	}

	return 0;
}
	
