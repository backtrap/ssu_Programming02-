#include <stdio.h>

#define PI 3.14

double circumference(double r) {
	return 2.0 * r * PI;
}

double area(double r) {
	return r * r * PI;
}

double volume(double r) {
	return 4.0 / 3.0 * r * r * r * PI;
}

double surface_area(double r) {
	return 4.0 * r * r * PI;
}

int main() {
	double r;
	printf("반지름을 입력하세요 : ");
	scanf("%lf", &r);

	printf("반지름이 %.3f인 \n", r);
	printf("	원의 원둘레 길이 : %.3f\n", circumference(r));
	printf("	원의 면적 : %.3f\n", area(r));
	printf("	구의 부피 : %.3f\n", volume(r));
	printf("	구의 표면적 : %.3f\n", surface_area(r));

	return 0;
}
