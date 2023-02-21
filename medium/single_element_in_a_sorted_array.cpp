#include <vector>

using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int size = nums.size(), left = 0, right = size - 1, mid = (left + right) / 2;
		if (size == 1)
			return nums[0];
		if (size == 3) {
			if (nums[0] == nums[1])
				return nums[2];
			else
				return nums[0];
		}
		while (1) {
			if (mid % 2 == 0) {
				if (nums[mid] == nums[mid + 1]) {
					left = mid;
				} else {
					if (nums[mid] == nums[mid - 1]) {
						right = mid;
					} else {
						return nums[mid];
					}
				}
			} else {
				if (nums[mid] != nums[mid + 1]) {
					if (nums[mid] != nums[mid - 1]) {
						return nums[mid];
					} else {
						left = mid;
					}
				} else {
					right = mid;
				}
			}
			mid = (left + right) / 2;
		}
	}
};