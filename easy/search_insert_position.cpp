#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int size = nums.size(), left = 0, right = size - 1, mid = (left + right) / 2;
		if (nums[left] > target)
			return 0;
		if (nums[right] < target)
			return size;
		if (nums[right] == target)
			return right;
		while (1) {
			if (nums[mid] > target) {
				if (nums[mid - 1] < target) {
					return mid;
				}
				right = mid;
			} else if (nums[mid] < target) {
				if (nums[mid + 1] > target) {
					return mid + 1;
				}
				left = mid;
			} else {
				return mid;
			}
			mid = (left + right) / 2;
		}
	}
};