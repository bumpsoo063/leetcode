#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int s = strs.size(), l = strs[0].length();
		int	cnt = 0;
		for (int i = 0; i < l; i++) {
			for (int j = 1; j < s; j++) {
				if (strs[j - 1][i] > strs[j][i]) {
					++cnt;
					break;
				}
			}
		}
		return cnt;
    }
};