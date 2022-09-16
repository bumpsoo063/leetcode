#include <cstdint>
class Solution {
public:
	int reverse(int x) {
		int ret = 0;
		if (x == 0) {
			return ret;
		}
		bool f = (x > 0) ? true : false;
		if (f) {
			while (x > 0) {
				if (ret > INT32_MAX / 10) {
					return 0;
				}
				ret = (ret * 10) + (x % 10);
				x /= 10;
			}
		} else {
			while (x < 0) {
				if (ret < INT32_MIN / 10) {
					return 0;
				}
				ret = (ret * 10) + (x % 10);
				x /= 10;
			}
		}
		return ret;
	}
};