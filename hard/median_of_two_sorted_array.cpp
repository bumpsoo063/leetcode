#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int s1 = nums1.size(), s2 = nums2.size();
		int i = 0, j = 0;
		vector<int> tmp;
		while (i < s1 && j < s2) {
			if (nums1[i] > nums2[j]) {
				tmp.push_back(nums2[j++]);
			} else {
				tmp.push_back(nums1[i++]);
			}
		}
		while (i < s1) {
			tmp.push_back(nums1[i++]);
		}
		while (j < s2) {
			tmp.push_back(nums2[j++]);
		}
		int s = tmp.size();
		if (s % 2) {
			return tmp[s / 2];
		} else {
			return (tmp[s / 2] + tmp[s / 2 -1]) / 2.0;
		}
	}
};
