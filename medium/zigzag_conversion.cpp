#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows <= 1)
			return s;
        vector<string> vs = vector<string>(numRows);
		bool f = true;
		for (int i = 0, j = s.size(), a = 0, b = 0; i != j; i++) {
			if (a == numRows) {
				a = 1;
				f = false;
			}
			if (b == numRows - 1) {
				b = 0;
				f = true;
			}
			if (f == true) {
				vs[a].push_back(s[i]);
				a++;
			} else {
				vs[numRows - 2 - b].push_back(s[i]);
				b++;
			}	
		}
		string ret;
		for (int i = 0; i < numRows; i++) {
			ret += vs[i];
		}
		return ret;
    }
};