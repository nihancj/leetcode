#include <stdio.h>
#include <stdlib.h>

struct matrix {
	_Bool isComplete;
	unsigned int possibleWays;
};
typedef struct matrix matrixNode;

matrixNode **generateMatrix(char m, char n) {
	matrixNode **array = (matrixNode **)malloc(sizeof(matrixNode *) * m);
	for (size_t row = 0; row < m; row++) {
		array[row] = (matrixNode *)malloc(sizeof(matrixNode) * n);
		for (size_t column = 0; column < n; column++) {
			array[row][column] = *(matrixNode *) malloc(sizeof(matrixNode));
			array[row][column].isComplete = 0;
		}
	}
	return array;
}

void printMatrix(matrixNode **array, char m, char n) {
	for (short row = 0; row < m; row++) {
		for (short col = 0; col < n; col++) {
			printf("%d[%d] - ", array[row][col].isComplete, array[row][col].possibleWays);
		}
		printf("\n");
	}
}


int findUniquePaths(matrixNode **array, char m, char n, char row, char col) {
	int paths = 0;
	// Over the border
	if (row > m-1 || col > n-1) {
		return 0;
	}

	// already searched
	if (array[row][col].isComplete == 1) {
		return array[row][col].possibleWays;
	}
	// Reached end goal
	if (row == m-1 && col == n-1) {
		return 1;
	}
	// Go right and down
	paths += findUniquePaths(array, m, n, row, col+1);
	paths += findUniquePaths(array, m, n, row+1, col);
	array[row][col].possibleWays = paths;
	array[row][col].isComplete = 1;
	return paths;
}

int uniquePaths(char m, char n) {
	matrixNode **array = generateMatrix(m, n);
	printMatrix(array, m, n);
	int uniquePaths = findUniquePaths(array, m, n, 0, 0);
	printf("%d\n", uniquePaths);
	free(array);
	return uniquePaths;
}

int main() {
	char m = 3;
	char n = 7;
	uniquePaths(m, n);
	return 0;
}
