#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

uint getResult(int tmp, int* nums, short numsSize, short target) {
	uint result = 0;
	for (short i = 0; i < numsSize; i++) {
		if (tmp + nums[i] > target) {
			return result;
		}
		if (tmp + nums[i] == target) {
			result++;
			continue;
		}
		uint result_temp = getResult(tmp+nums[i], nums, numsSize, target);
		result += result_temp;
	}
	return result;
}

uint combinationSum4(int* nums, short numsSize, short target){
	return getResult(0, nums, numsSize, target);
}

int main() {
	short numsSize = 3;
	int *nums = malloc(sizeof(int) * numsSize);
	nums[0] = 2;
	nums[1] = 1;
	nums[2] = 3;
	// nums[3] = 6;
	// nums[4] = 7;
	// nums[5] = 8;
	// nums[6] = 3;
	// nums[7] = 10;
	printf("%d\n", combinationSum4(nums, numsSize, 35));
	free(nums);
	return 0;
}
