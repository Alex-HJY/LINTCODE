class Solution {
public:
	/*
	* @param root: a TreeNode, the root of the binary tree
	* @return:
	*/
	TreeNode *dfs(TreeNode *node) {
		if ((!node->left) && (!node->right)) return node;
		TreeNode *l = node->left;
		TreeNode *r = node->right;
		TreeNode *temp;
		if (l) {
			temp = dfs(l);
			node->right = l;
			temp->right = r;
		}
		node->left = NULL;
		if (r) {
			return dfs(r);
		}
		return (temp);

	}
	void flatten(TreeNode * root) {
		// write your code here
		if (root) {
			dfs(root);
		}
	}
};
