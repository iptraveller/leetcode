/*
AAABCCCDEEEFG
A C E G
ABCDEF
A C E
ACEGABCDEFACE

AAAABCDDDDEFGGG
A  D  G
A CD FG
AB DE G
A  D
ADGACDFGABDEGAD

AAAAABCDEEEEEFGHIII
A   E   I 0 +(n-1)+(n-1) +(n-1)+(n-1) 
A  DE  HI 1 +(n-2)+(n-2) +1*2 +(n-2)+(n-2)
A C E G I 2 +(n-3)+(n-3) +2*2 +(n-3)+(n-3)
AB  EF    3 +(n-4)+(n-4) +3*2 +(n-4)+(n-4)
A   E     4 +(n-1)+(n-1) +(n-1)+(n-1)
AEIADEHIACEGIABEFAE

P   A   H   N
A P L S I I G
Y   I   R

P   A   Y   P
A N L S I I G
H   I   R
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

/* Memory Limit Exceeded */

class Solution {
public:
    string convert(string s, int nRows) {
        string r = "";
		int i, j, k;
		
		if (nRows == 1) {
			return s;
		}
		for (i = 0; i < nRows; i++) {
			for (j = i, k = 0; j < s.length(); k++) {
				r.append(s, j, 1);
				if (i == 0 || i == nRows - 1) {
					j += 2 * (nRows - 1);
				} else if (k & 1) {
					j += 2 * i;
				} else {
					j += 2 * (nRows - (i + 1));
				}
			}
		}
		return r;
    }
};

int main()
{
	Solution *s = new Solution();
	string str = "PAYPALISHIRING";

	string r = s->convert(str, 3);
	cout << r << endl;

	str = "AAABCCCDEEEFG";
	r = s->convert(str, 3);
	cout << r << endl;

	str = "AAAABCDDDDEFGGG";
	r = s->convert(str, 4);
	cout << r << endl;

	str = "AAAAABCDEEEEEFGHIII";
	r = s->convert(str, 5);
	cout << r << endl;

	str = "ABCDE";
	r = s->convert(str, 5);
	cout << r << endl;

	str = "ABCDE";
	r = s->convert(str, 1);
	cout << r << endl;

	return 0;
}