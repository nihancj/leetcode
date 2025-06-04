#include <string.h>

int pal_start(int *s, int *h, int *t, int last) {
	int head = *h, tail = *t;
	int count = 0;
	while (tail != 0 && head != last) {
		head++; tail--;
		if (s[head] != s[tail]) return count*2;
		count++;
		*h = head; *t = tail;
	}
	return count*2;
}

char* longestPalindrome(char* s) {
	int len = strlen(s);
	int i, size=1, max=1, max_index=0;
	if (len > 2 && s[1] == s[0]) {
		size = 2; max = 2;
	}

	int head;
	for (i = 2; i < len; i++) {
		head = i-2;
		if (s[i] == s[head]) {
			pal_start(s, &head, &i, len-1);
		}
	}
}

int main(int argc, char *argv[]) {
	return 0;
}
