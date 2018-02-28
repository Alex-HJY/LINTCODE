class BSTIterator {
public:
	vector<TreeNode *> inorder;
	int current;
	/*
	* @param root: The root of binary tree.
	*/
	void dfs(TreeNode *p)
	{
		if (!p) return;
		dfs(p->left);
		inorder.push_back(p);
		dfs(p->right);
	}
	BSTIterator(TreeNode * root)
	{
		dfs(root);
		current = 0;
	}
	/*
	* @return: True if there has next node, or false
	*/
	bool hasNext() {
		// write your code here
		if (current == inorder.size()) return false;
		else { return true; }
	}

	/*
	* @return: return next node
	*/
	TreeNode * next() {
		// write your code here
		return inorder[current++];
	}
};
