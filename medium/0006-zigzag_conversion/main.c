#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incriment(int *n) {
	++*n;
}
void decriment(int *n) {
	--*n;
}

char* convert(char* s, int numRows) {
	short int len = strlen(s);
	char *str = malloc((len+1) * sizeof(char));
	int *q_rear = malloc(numRows * sizeof(int));
	char **queues = malloc(numRows * sizeof(char *));
	int one_cycle = (numRows==1)? 1: numRows*2 - 2;
	int my_sauce = len/one_cycle + 1;
	int my_sauce2 = my_sauce * 2;

	memset(q_rear, 0, numRows);
	queues[0] = malloc(my_sauce * sizeof(char));
	q_rear[0] = -1;
	if (numRows-- != 1) {
		queues[numRows] = malloc(my_sauce * sizeof(char));
		q_rear[numRows] = -1;
	}
	for (int i=1; i<numRows; i++) {
		queues[i] = malloc(my_sauce2 * sizeof(char));
		q_rear[i] = -1;
	}

	void (*add_minus)(int *n) = &incriment;
	for (int i = 0, j=-1; i < len; i++) {
		add_minus(&j);
		// printf("%d\n", q_rear[j]);
		q_rear[j] += 1;
		// printf("%d %ld %c\n", j, q_rear[j], s[i]);
		queues[j][q_rear[j]] = s[i];
		// printf("%c %d\n", s[i], j);
		if (numRows == 0) j=-1;
		else if (j == numRows) add_minus = &decriment;
		else if (j%one_cycle == 0) add_minus = &incriment;
		// printf("%c %d %d\n", queues[j][q_rear[j]-1], j, q_rear[j]-1);
	}

	for (int k = 0, i = 0; i <= numRows; i++) {
		for (int j = 0; j <= q_rear[i]; j++) {
			str[k++] = queues[i][j];
			// printf("%c %d %d\n", queues[i][j], i, j);
			// printf("%c %d\n", str[k-1], k-1);
		}
	}
	str[len] = '\0';



	for (int i=0; i<numRows; i++) {
		free(queues[i]);
	}
	free(queues);
	free(q_rear);
	return str;
}

int main() {
	char str[20] = "AB";
	int numRows = 1;
	char *new = convert(str, numRows);
	printf("%s\n" , new);
	free(new);
	return 0;
}
