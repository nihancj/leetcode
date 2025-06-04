#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** fizzBuzz(int n, int* returnSize){
	*returnSize = n;
	char ** answer = (char **)malloc(sizeof(char*)*n);
	for (int i = 1; i <= n ; i++) {
		if (i % 15 == 0) {
			answer[i-1] = (char *)malloc(sizeof(char)*9);
			answer[i-1] = "FizzBuzz";
			continue;
		}
		answer[i-1] = (char *)malloc(sizeof(char)*5);
		if (i % 5 == 0) {
			answer[i-1] = "Buzz";
		} else if (i % 3 == 0) {
			answer[i-1] = "Fizz";
		} else {
			sprintf(answer[i-1], "%d", i);
		}
	}
	return answer;
}


int main() {
	int returnSize;
	char **answer = fizzBuzz(48, &returnSize);
	for (size_t i = 0; i < returnSize; i++) {
		printf("%s\n", answer[i]);
	}
	free(answer);
	return 0;
}
