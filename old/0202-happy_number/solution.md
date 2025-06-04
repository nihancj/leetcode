# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Will the number go to infinity? Will it loop back to itself? Will it go to zero?

First of all, it won't go to infinity. Why? Because in base 10 numerals the maximum value a digit can have is 9. 9 squared is 81. Our constraint is 2^31 which has 10 digits. So the maximum it will get is 81 * 10 = 810.
Forget infinity it is never going past 810.

Two things can happen either it eventually gets to 1 or it ends up in a loop.
So the next obvious question to ask is: Does the number loop back to itself if it ends up in a loop?
Let's find out....

Take the number 2 as an example. Follow it closely as is continuously squares it's digits and adds them.
2 -> 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4 -> ...
We can see that 2 goes in a loop but it didn't loop back to itself. So that approach won't work here.

By now you might have already figured out you can brute force this stuff by storing every result you get in an array and check it in every iteration. You can go ahead and implement that code if you like. (Note: brute forcing approach here is not as taxing as you think since after the 4th iteration the number wont even go past 200.)

Since you decided to stick around, I will tell you a cheatcode.
4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4
Every non happy number will eventually end up in this loop. Why? I don't know. That's why it's a cheat code.

# Approach
<!-- Describe your approach to solving the problem. -->
Reinforced with the knowledge that we now have, it should be a walk in the park.
First, we get the one's digit by doing `n % 10` then we square the result and store it in a variable (`sum`).
We have successfully squared one of the digits. To get to the tenth's digit we will `n / 10` . Now it's in one's digit. SO we continue the process and keep adding to the variable (sum) until n reaches 0.

Now we have got our new number. Set n to the new number and reset sum to be 0 and repeat the process.
Before that we should also check if the new number is either 1 or if it is any of the number that appears in the loop. For simplicity sake, we just compare it to one of the elements in the loop, say 4.

# Code
```
_Bool isHappy(int n) {
	short sum;
	do {
		sum = 0;
		while (n) {
			sum += (n % 10) * ( n % 10);
			n /= 10;
		}
		n = sum;
	} while (n != 1 && n != 4);
	return 1*(n == 1);
}
```
