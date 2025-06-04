/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	for (int i=0; i<numsSize; i++) {
		for (int j=0; j<numsSize; j++) {
			if (i==j) continue;
			if (target-nums[i] == nums[j]) {
				int *num = malloc(sizeof(num)*2);
				num[0] = i;
				num[1] = j;
				*returnSize = 2;
				return num;
			}
		}
	}
	returnSize = 0;
	return NULL;
}

int main(int argc, char *argv[])
{
	int arr[5] = {1,2,3,4,5};
	int *ans = twoSum(arr, 5, 5, 2);
	return EXIT_SUCCESS;
}
