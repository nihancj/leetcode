#include <stdio.h>

char maximumWealth(int** accounts, int row, int* col) {
	char big = 0;
	short tempMoney;
	for (short person = 0; person < row; person++) {
		tempMoney = 0;
		for (short account = 0; account < *col; account++) {
			tempMoney += accounts[person][account];
		}
		if (tempMoney > big) {
			big = tempMoney;
		}
	}
	return big;
}

int main() {
	int accounts[][50] = {{2,8,7},{7,1,3},{1,9,5}};
	int *acc_ptr = accounts[0];
	int col = 3;

	maximumWealth(&acc_ptr, 3, &col);

	return 0;
}
