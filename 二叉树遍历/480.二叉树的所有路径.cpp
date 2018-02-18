class Solution {
public:
	/*
	* @param root: the root of the binary tree
	* @return: all root-to-leaf paths
	*/
	vector<string> ans;
	void dfs(TreeNode *node, string s) {
		TreeNode *l = node->left;
		TreeNode *r = node->right;
		if (l) {
			dfs(l, s + "->" + to_string(l->val));
		}
		if (r) {
			dfs(r, s + "->" + to_string(r->val));
		}
		if ((!l) && (!r)) {
			cout << s << endl;
			ans.push_back(s);
		}
		return;
	}
	vector<string> binaryTreePaths(TreeNode * root) {
		// write your code here
		if (root)
			dfs(root, to_string(root->val));
		return ans;
	}
};