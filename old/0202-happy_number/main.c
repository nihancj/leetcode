#include <stdio.h>

_Bool isHappy(int n) {
	short sum;
	do {
		sum = 0;
		while (n) {
			sum += (n % 10) * ( n % 10);
			n /= 10;
		}
		n = sum;
	} while (n != 1 && n != 4);
	return 1*(n == 1);
}

int main() {
	int input = 58;
	printf("%d\n", isHappy(input));
	return 0;
}
