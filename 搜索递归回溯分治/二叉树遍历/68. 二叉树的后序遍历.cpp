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
		if (r) {
			dfs(r);
		}
		ans.push_back(node->val);
	}
	vector<int> postorderTraversal(TreeNode * root) {
		// write your code here
		if (root)
			dfs(root);
		return ans;
	}
};
