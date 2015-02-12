#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
//#include <unordered_map>

using namespace std;

/* using multimap */
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		multimap<int, int> m;
		multimap<int, int>::iterator mi;
		vector<int> v;
		int index1, index2;

		for (int i = 0; i < numbers.size(); i++) {
			m.insert(pair<int,int>(numbers[i], i));
		}

		for (int i = 0; i < numbers.size(); i++) {
			int j = target - numbers[i];
			int found = 0;

			mi = m.find(j);
			while (mi != m.end() && mi->first == j) {
				if (mi->second == i) {
					mi++;
					continue;
				}
				found = 1;
				break;
			}
			if (!found) {
				continue;
			}
			index1 = i + 1;
			index2 = mi->second + 1;
			break;
			
		}
		v.push_back(index1);
		v.push_back(index2);
		cout << "index1=" << index1 << ", index2=" << index2 << '\n';
		return v;
	}
};

#if 0
/* using unorderd_multimap, c11 support */
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_multimap<int, int> m;
		unordered_multimap<int, int>::iterator mi;
		vector<int> v;
		int index1, index2;

		for (int i = 0; i < numbers.size(); i++) {
			m.insert(pair<int,int>(numbers[i], i));
		}

		for (int i = 0; i < numbers.size(); i++) {
			int j = target - numbers[i];
			int found = 0;

			mi = m.find(j);
			while (mi != m.end() && mi->first == j) {
				if (mi->second == i) {
					mi++;
					continue;
				}
				found = 1;
				break;
			}
			if (!found) {
				continue;
			}
			index1 = i + 1;
			index2 = mi->second + 1;
			break;

		}
		v.push_back(index1);
		v.push_back(index2);
		//cout << "index1=" << index1 << ", index2=" << index2 << '\n';
		return v;
	}
};
#endif

int main(void)
{
	vector<int> v;
	Solution *s = new Solution();

	v.push_back(0);
	v.push_back(4);
	v.push_back(3);
	v.push_back(0);
	s->twoSum(v, 0);
	v.clear();

	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	s->twoSum(v, 6);

	return 0;
}