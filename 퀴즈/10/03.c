#include "pi.h"

int main() {
	double r;
	printf("반지름을 입력하세요 : ");
	scanf("%lf", &r);

	printf("반지름이 %.3f인 \n", r);
	printf("	원의 원둘레 길이 : %.3f\n", CIRCUMFERENCE(r));
	printf("	원의 면적 : %.3f\n", AREA(r));
	printf("	구의 부피 : %.3f\n", VOLUME(r));
	printf("	구의 표면적 : %.3f\n", SURFACE_AREA(r));

	return 0;
}
