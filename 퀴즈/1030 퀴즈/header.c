#include "headerfile.h"

#if defined(PI)
	#undef PI
	#define PI 3.141592
#endif

int main() {
	printf("%f\n", PI);

	return 0;
}
