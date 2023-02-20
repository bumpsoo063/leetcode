#include <vector>
#include <iostream>
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
private:
	queue<TreeNode*> q;
	void helper(TreeNode* root, int depth) {
		TreeNode *tmp, *first, *second;
		tmp = q.front();
		if (tmp == nullptr)
			return ;
		q.pop();
		if (depth % 2) {
			first = tmp->left;
			second = tmp->right;
		} else {
			first = tmp->right;
			second = tmp->left;
		}
		q.push(first);
		q.push(second);

	}
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		q.push(root);
		int i = 0;
		while (1) {
			TreeNode* tmp = q.front();
			if (tmp == nullptr)
				break;
			q.pop();
			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
		}
		return vector<vector<int>>();
	}
};
int main() {
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->left->left = new TreeNode(15);
	root->left->right = new TreeNode(7);
	Solution s;
	s.zigzagLevelOrder(root);
}