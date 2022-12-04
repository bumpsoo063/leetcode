#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int ret = 0;
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			v.push_back(i);
		}
		for (int i = 0; i < n; i ++) {
			do {
				ret++;
			} while (next_permutation(v.begin(), v.begin() + i));
		}
		return ret;
    }
};