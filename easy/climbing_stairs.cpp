#include <queue>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		int i = 1;
		int tmp;
		queue<int> q;
		while (i <= n) {
			if (i == 1 || i == 2)
				q.push(i);
			else {
				tmp = q.front();
				q.pop();
				tmp += q.front();
				q.push(tmp);
			}
			++i;
		}
		q.pop();
		return q.front();
    }
};