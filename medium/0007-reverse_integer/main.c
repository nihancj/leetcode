#include <limits.h>
#include <stdint.h>
#include <stdio.h>


int reverse(int x){
	// _Bool sign = (x & INT_MIN)? 1: 0;
	int max = (x & INT_MIN)? INT_MIN: INT_MAX; // return 0 or INT_MIN for +ve or -ve
	int y=0;
	for (int digits = (x%10 != 0); x; digits++) {
		y = y*10 + x % 10;
		x /= 10;
		printf("y - %d\n", y);
		if (digits == 9 && x) {
			int diff = y % (max/10);
			printf("max/10 - %d\n", max/10);
			printf("diff - %d\n", diff);
			if (diff == y) continue;
			if (diff == 0) {
				if (x % (max%10+1) != x) {
					printf("x10 - %d\nmax10 - %d\n", x, max%10);
					return 0;
				}
			} else return 0;
		}
	}
	return y;
}

int main() {

	int x = -1463847412;
	printf("x - %d\n", x);
	int y = reverse(x);
	printf("y - %d\n", y);
	return 0;
}
