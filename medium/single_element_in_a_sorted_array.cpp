#include <vector>

using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int size = nums.size(), left = 0, right = size - 1, mid;
		while (1) {
			mid = (left + right) / 2;
			if (mid == 0 || mid == size - 1)
				return nums[mid];
			if (mid % 2 == 0) {
				if (nums[mid] == nums[mid + 1]) {
					left = mid + 1;
				} else {
					if (nums[mid] == nums[mid - 1]) {
						right = mid - 1;
					} else {
						return nums[mid];
					}
				}
			} else {
				if (nums[mid] != nums[mid + 1]) {
					left = mid + 1;
				} else {
					if (nums[mid] != nums[mid - 1]) {
						right = mid - 1;
					} else {
						return nums[mid];
					}
				}
			}
		}
	}
};