class Solution {
public:
	/*
	* @param root: A Tree
	* @return: Preorder in ArrayList which contains node values.
	*/
	vector<int> ans;
	void dfs(TreeNode *node) {
		TreeNode *l = node->left;
		TreeNode *r = node->right;
		if (l) {
			dfs(l);
		}
		ans.push_back(node->val);
		if (r) {
			dfs(r);
		}
	}
	vector<int> inorderTraversal(TreeNode * root) {
		// write your code here
		if (root)
			dfs(root);
		return ans;
	}
};
