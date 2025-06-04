#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool canConstruct(char * ransomNote, char * magazine){
	char *ptr;
	for (size_t i = 0; ransomNote[i] != '\0'; i++) {
		ptr = strchr(magazine, ransomNote[i]);
		if (ptr == NULL) {
			return false;
		}
		ptr[0] = ' ';
	}
	return true;
}

int main() {
	char *ransomNote = (char *)malloc(sizeof(char)* 4);
	ransomNote[0] = 'a';
	ransomNote[1] = 'a';
	char *magazine = (char *)malloc(sizeof(char)* 4);
	magazine[0] = 'a';
	magazine[1] = 'b';
	if (canConstruct(ransomNote, magazine) == true) {
		printf("Can construct\n");
	} else {
		printf("Cannot construct\n");
	}
	free(ransomNote);
	free(magazine);
	return 0;
}
