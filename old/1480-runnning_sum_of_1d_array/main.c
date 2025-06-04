#include <stdio.h>
#include <stdlib.h>

int *runningSum(int *nums, int numSize, int *returnSize) {
	int runningSum = 0;
	*returnSize = numSize;
	int *output = (int *) malloc(numSize*sizeof(int));
	for (short i = 0; i < numSize; i++) {
		runningSum += nums[i];
		output[i] = runningSum;
	}

	return output;
}

int main() {
	int input[] = { 3, 1, 2, 10, 1 };
	const int totalInputs = sizeof(input) / sizeof(input[0]);
	int outputSize;

	int *output = runningSum(&input[0], totalInputs, &outputSize);
	printf("%d\n", output[0]);
	printf("%d\n", output[1]);
	printf("%d\n", output[2]);
	printf("%d\n", output[3]);
	printf("%d\n", output[4]);

	free(output);
	return 1;
}
