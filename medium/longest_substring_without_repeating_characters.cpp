#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
        int ret = 0;
		for (auto i = 0; s[i]; i++) {
			for (auto len = 0; i + len <= s.size() ; len++) {
				string tmp = s.substr(i, len);
				if (i + len == s.size() || tmp.find(s[i + len]) != s.npos) {
                    			if (ret < len) {
					    ret = len;
					}
					break ;
				}
			}
		}
		return ret;
	}
};
