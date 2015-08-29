#include <stdio.h>

int main(){
	int z, x = 5, y = -13, a = 4, b = 2;
	z = x++ - --y * b / a;
	printf("%d\n", z);
	return 0;
}
