#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int *nums3 = malloc(sizeof(int)*nums1Size);
	int i=0, j=0, k=0;
	while (i < m && j < n) {
		if (nums1[i] <= nums2[j]) {
			nums3[k++] = nums1[i++];
		} else {
			nums3[k++] = nums2[j++];
		}
	}
	while (i < m) {
		nums3[k++] = nums1[i++];
	}
	while (j < n) {
		nums3[k++] = nums2[j++];
	}

	for(int i=0; i<nums1Size; nums1[i] = nums3[i], i++);
	free(nums3);
}

int main(int argc, char *argv[]) {
	int nums1[8] = {5, 6 ,8, 10};
	int nums2[4] = {1, 22 ,29, 90};
	merge(nums1, 8, 4, nums2, 4, 4);
	for(int i=0; i<8; printf("%d\t", nums1[i++]));
}
