#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution {
private:
	int power_of_ten(int x) {
		int n = 1;
		for (int i = 0; i < x; i++) {
			n *= 10;
		}
		return n;
	}
	int log_of_ten(int x) {
		int n = 0;
		do {
			n++;
			x /= 10;
		} while (x);
		return n - 1;
	}
public:
    bool isPalindrome(int x) {
		int i, n;	
		if (x < 0) {
			return false;
		}    
		n = log_of_ten(x);    
		for (i = 0; i <= n; i++) {
			if ((x / power_of_ten(i)) % 10 != (x / power_of_ten(n - i)) % 10) {
				return false;
			}
		}
		return true;
    }
};

int main()
{
	Solution *s = new Solution();
	
	printf("-1: %d\n", s->isPalindrome(-1));
	printf(" 1: %d\n", s->isPalindrome(1));
	printf(" 0: %d\n", s->isPalindrome(0));
	printf(" 3: %d\n", s->isPalindrome(3));	
	printf("11: %d\n", s->isPalindrome(11));
	printf("12: %d\n", s->isPalindrome(12));
	printf("123454321: %d\n", s->isPalindrome(123454321));
	
	return 0;
}