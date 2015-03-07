#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
		int s = x, r = 0;
		while (s) {
			if (r > 214748364 || r < -214748364) {
				return 0;
			}
			r *= 10;
			if (x > 0 && r + s % 10 < r || x < 0 && r + s % 10 > r) {
				return 0;
			}
			r += s % 10;
			s /= 10;
		}
		return r;
    }
};

int main(void)

{
	Solution *s = new Solution();
	
	printf("%d\n", s->reverse(123));
	printf("%d\n", s->reverse(-123));
	printf("%d\n", s->reverse(0));
	printf("%d\n", s->reverse(10));
	printf("%d\n", s->reverse(1000000003));
	printf("%d\n", s->reverse(-1000000003));
	printf("%d\n", s->reverse(-1999999999));
	return 0;
}
