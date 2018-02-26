class Solution {
public:
	/*
	* @param root: The root of binary tree.
	* @return: True if the binary tree is BST, or false
	*/
	vector<int> s;
	void dfs(TreeNode *p)
	{
		if (!p) return;
		dfs(p->left);
		s.push_back(p->val);
		dfs(p->right);
	}
	bool isValidBST(TreeNode * root) {
		if (!root) return true;
		// write your code here
		dfs(root);
		int t = s.size();
		if (t<2) return true;
		for (int i = 1; i < t; ++i)
		{
			if (s[i] <= s[i - 1]) return false;
		}
		return true;
	}
};
