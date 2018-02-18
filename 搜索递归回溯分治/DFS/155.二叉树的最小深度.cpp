class Solution {
public:
	/*
	* @param root: The root of binary tree
	* @return: An integer
	*/
	int ans = INT_MAX;
	void dfs(TreeNode *node, int level) {
		if ((!node->left) && (!node->right)) {
			ans = min(ans, level);
			return;
		}
		if (node->left)
			dfs(node->left, level + 1);
		if (node->right)
			dfs(node->right, level + 1);

	}
	int minDepth(TreeNode * root) {
		// write your code here
		if (!root)
			ans = 0;
		else
			dfs(root, 1);
		return ans;
	}
};