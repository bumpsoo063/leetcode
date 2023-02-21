#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		int level = 0, level_size, i =0;
		TreeNode *tmp;
		queue<TreeNode*> q;
		vector<vector<int>> ret;
		q.push(root);
		if (root == nullptr)
			return ret;
		while (!q.empty()) {
			i = 0;
			level_size = q.size();
			vector<int> vec(level_size);
			while (i < level_size) {
				tmp = q.front();
				q.pop();
				if (level % 2) {
					vec[i++] = tmp->val;
				} else {
					vec[level_size - i++ - 1] = tmp->val;
				}
				if (tmp->right) q.push(tmp->right);
				if (tmp->left) q.push(tmp->left);
			}
			ret.push_back(vec);
			level++;
		}
		return ret;
	}
};