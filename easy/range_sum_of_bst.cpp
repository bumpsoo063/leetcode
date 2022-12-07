/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Definition for a binary tree node.
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
	void depth(TreeNode *root, int low, int high, int &ret) {
		if (root == nullptr)
			return;
		depth(root->left, low, high, ret);
		depth(root->right, low, high, ret);
		if (low <= root->val && root->val <= high)
			ret += root->val;	
	}
	int rangeSumBST(TreeNode* root, int low, int high) {
		int	ret = 0;
		depth(root, low, high, ret);
		return ret;
	}
};