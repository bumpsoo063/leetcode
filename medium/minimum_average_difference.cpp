#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long right = 0;
		for (int i : nums) {
			right += i;
		}
		long left = 0;
		long min = 100000000000, ret = 0;
		for (int i = 0, size = nums.size(); i < size; i++) {
			right -= nums[i];
			left += nums[i];
			long tmp;
			if (size - i - 1 == 0)
				tmp = left / (i + 1);
			else
				tmp = left / (i + 1) - right / (size - i - 1);
			if (tmp < 0)
				tmp *= -1;
			if (min > tmp) {
				ret = i;
				min = tmp;
			}
		}
		return ret;
    }
};