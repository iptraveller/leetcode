#include <iostream>
#include <stdio.h>
#include <string>
#include <limits.h>
using namespace std;

class Solution {
public:
	int atoi(string str) {
		int i, op = 0, headspace = 0, tailspace = 0;
		unsigned int val = 0;
		
		for (i = 0; str[i] != '\0'; i++) {
			if (str[i] == ' ') {
				if (headspace) {
					tailspace = 1;
				}
				continue;
			}
			if (tailspace) {
				// "123 123"
				break;
			}
			headspace = 1;
			if (str[i] == '+' || str[i] == '-') {
				if (op != 0) {
					// "++123"
					return 0;
				}
				op = (str[i] == '+') ? 1 : -1;	
			} else if (str[i] >= '0' && str[i] <= '9') {
				if (val > (unsigned int) INT_MAX / 10) {
					// 444444444
					return op < 0 ? INT_MIN : INT_MAX;
				}
				val = val * 10;
				val += str[i] - '0';
				if (op < 0 && val > (unsigned int) INT_MAX + 1 || op >= 0 && val > (unsigned int) INT_MAX) {
					// 2147483648
					return op < 0 ? INT_MIN : INT_MAX;	
				}
			} else {
				// 123abcd
				break;
			}
		}
		return op < 0 ? -val : val;
	}
};

int main(void)
{	
	Solution *s = new Solution();
	
	printf("%d\n", s->atoi(string("0")));
	printf("%d\n", s->atoi(string("1")));
	printf("%d\n", s->atoi(string("-1")));
	printf("%d\n", s->atoi(string("2147483647")));
	printf("%d\n", s->atoi(string("-2147483648")));
	printf("%d\n", s->atoi(string("2147483647   ")));
	printf("%d\n", s->atoi(string("   -2147483648")));
	printf("%d\n", s->atoi(string(" +-123 ")));
	printf("%d\n", s->atoi(string(" 2147483648 ")));
	printf("%d\n", s->atoi(string(" -2147483649 ")));
	printf("%d\n", s->atoi(string("- 1")));
	printf("%d\n", s->atoi(string("  -0012a42")));
	
	return 0;
}
