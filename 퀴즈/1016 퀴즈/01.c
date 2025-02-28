#include <stdio.h>

float tri_area_f(float w, float h) {return w * h / 2;}

#define TRI_AREA(w, h) ((w) * (h) / 2)

int main(void) {

float a;

a = tri_area_f(1, 1);

printf("The area is %f\n", a);

a = TRI_AREA(1, 1);

printf("The area is %f\n", a);

return 0;

}