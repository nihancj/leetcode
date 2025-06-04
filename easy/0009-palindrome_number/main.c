#include <stdbool.h>


bool isPalindrome(int x) {
	if (x<0) return false;
	unsigned int rev=0, org=x;
	while (x != 0) {
		rev = rev*10 + x%10;
		x /= 10;
	}
	if (rev == org) return true;
	return false;
}
