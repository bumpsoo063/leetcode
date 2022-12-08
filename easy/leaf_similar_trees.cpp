#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
	void depth(TreeNode *root, vector<int> &v) {
		if (root == nullptr) 
			return ;
		if (root->left == nullptr && root->right == nullptr) {
			v.push_back(root->val);
			return ;
		}
		depth(root->left, v);
		depth(root->right, v);
	}
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> v1, v2;
		depth(root1, v1);
		depth(root2, v2);
		int i1 = 0, i2 = 0, s1 = v1.size(), s2 = v2.size();
		while (i1 < s1 && i2 < s2) {
			if (v1[i1++] != v2[i2++])
				return false;
		}
		if (i1 != i2 || s1 != s2)
			return false;
		return true;
	}
};