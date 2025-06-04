#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSize){
	int **array = (int **) malloc(sizeof(int *) * numRows);
	*returnSize = numRows*(numRows+1)/2;
	returnColumnSize = (int **)malloc(sizeof(int *) * numRows);

	for (short i = 0; i < numRows; i++) {
		returnColumnSize[i] = (int *)malloc(sizeof(int) * 2);
		returnColumnSize[i][0] = i+1;
		array[i] = (int *) malloc(sizeof(int) * (i+1));
		array[i][0] = 1;
		assert(array[i][0] == 1 && returnColumnSize[i][0] == i+1);
		if (i >= 2) {
			assert(array[i][0] == 1 && returnColumnSize[i-1][0] == i);
			for (short k = 1; k < i; k++) {
				array[i][k] = array[i-1][k-1] + array[i-1][k];
			}
		}
		array[i][i] = 1;
	}

	return array;
}

void print_array(int **array,short rows) {
	for (short i = 0; i < rows; i++) {
		for (short k = 0; k <= i ; k++) {
			printf("%d,", array[i][k]);
		}
		free(array[i]);
		printf("\n");

	}
}

int main() {
	short rows = 2;
	int returnSize;
	int **returnColumnSizes;
	int **array = generate(rows, &returnSize, returnColumnSizes);
	print_array(array, rows);
	// assert(**returnColumnSizes == 1);
	printf("%d\n", **returnColumnSizes);
	return 0;
}
