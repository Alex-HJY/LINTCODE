/**
* Definition of TreeNode:
* class TreeNode {
* public:
*     int val;
*     TreeNode *left, *right;
*     TreeNode(int val) {
*         this->val = val;
*         this->left = this->right = NULL;
*     }
* }
*/


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
		ans.push_back(node->val);
		if (l) {
			dfs(l);
		}
		if (r) {
			dfs(r);
		}
	}
	vector<int> preorderTraversal(TreeNode * root) {
		// write your code here
		if (root)
			dfs(root);
		return ans;
	}
};