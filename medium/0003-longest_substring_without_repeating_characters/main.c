#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
	int len = strlen(s);
	short int hmap[128] = {0};
	int big = 0, n = 0, to_clean = 0;

	for (int i=0; i<len; i++) {
		if (hmap[s[i]]) {
			if (n > big) big = n;
			n = i - hmap[s[i]];
			int j;
			for (j=to_clean, to_clean=hmap[s[i]]; j<to_clean; j++) {
				hmap[s[j]] = 0;
			}
		}
		hmap[s[i]] = i+1;
		n++;
	}

	if (n > big) big = n;

	return big;
}

int main() {
	char str[] = "abcabcbb";
	printf("%d", lengthOfLongestSubstring(str));
	return 0;
}
