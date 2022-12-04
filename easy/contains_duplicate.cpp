#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> s;
		pair<set<int>::iterator, bool> p;
		for (int i = 0, size = nums.size(); i < size; i++) {
			p = s.insert(nums[i]);
			if (p.second == false) {
				return true;
			}
		}
		return false;
	}
};