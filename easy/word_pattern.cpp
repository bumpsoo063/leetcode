#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
		unordered_set<string> se;
		stringstream ss(s);
		string tmp;
		for (auto i : pattern) {
			if (getline(ss, tmp, ' ')) {
				if (m[i].length() > 0) {
					if (m[i] != tmp)
						return false;
				} else {
					m[i] = tmp;
					if (se.find(tmp) != se.end())
						return false;
					se.insert(tmp);
				}
			} else {
                return false;
            }
		}
		if (getline(ss, tmp, ' '))
			return false;
		return true;
    }
};