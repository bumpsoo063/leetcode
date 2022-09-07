#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int size = s.size();
		if (size == 1) {
			return s;
		}
		int ret_offset = 0, ret_len = 0;
		for (auto i = 0; i < size; i++) {
			for (auto len = 1; i + len <= size; len++) {
				if (is_palin(s, i, len)) {
					if (ret_len < len) {
						ret_len = len;
						ret_offset = i;
					}
				}
			}
			if (size < i + ret_len) {
				break ;
			}
		}
		return s.substr(ret_offset, ret_len);
	}
	bool is_palin(string &s, int offset, int len) {
		for (auto i = 0; i < len / 2; i++) {
			if (s[offset + i] != s[offset + len - 1 - i]) {
				return false;
			}
		}
		return true;
	}
};