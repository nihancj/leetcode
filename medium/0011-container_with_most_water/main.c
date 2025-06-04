#include <stdio.h>

int max_area(int *height, int n) {
	int max, area, mi, i=0, j=n-1;
	while (i != j) {
		mi = (height[i] < height[j])? i: j;
		area = height[mi] * (j-i);
		if (area > max) {
			max = area;
		}
		(mi == i)? i++: j--;
	}
	return max;
}

int main() {
	int height[7] = {1, 5 , 9, 1, 9 , 3, 7};
	printf("%d\n", max_area(height, 7));
}
