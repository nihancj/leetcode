#include <stdio.h>

short numberOfSteps(int num) {
	short steps = num % 2 != 0;
	num -= steps;
	while (num != 0) {
		do {
			num /= 2;
			++steps;
		} while (num % 2 == 0);
		--num;
		++steps;
	}
	return steps;
}

int main() {
	int num = 12;
	int steps = numberOfSteps(num);
	printf("%d\n", steps);


	return 0;
}
