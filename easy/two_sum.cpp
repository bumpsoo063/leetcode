#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int s = nums.size();
		for (auto i = 0; i < s; i++) {
			for (auto j = i + 1; j < s; j++) {
				if (nums[i] + nums[j] == target) {
					return {i, j};
				}
			}
		}
		return {0, 0};
	}
};
