#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

uint getResult(int goal, int* nums, short numsSize, short target) {
	uint result = 0;
	for (short i = 0; i < numsSize; i++) {
		int tmp = target % nums[i];

		if (tmp == goal) {
			result++;
			goal = target - nums[i];
		} else {
			goal = target - tmp;
		}





		result += getResult(goal, nums, numsSize, target);
	}
	return result;
}

uint combinationSum4(int* nums, short numsSize, short target){
	return getResult(0, nums, numsSize, target);
}

int main() {
	short numsSize = 2;
	int *nums = malloc(sizeof(int) * numsSize);
	nums[0] = 1;
	nums[1] = 2;
	// nums[2] = 3;
	// nums[3] = 6;
	// nums[4] = 7;
	// nums[5] = 8;
	// nums[6] = 3;
	// nums[7] = 10;
	printf("%d\n", combinationSum4(nums, numsSize, 4));
	free(nums);
	return 0;
}
