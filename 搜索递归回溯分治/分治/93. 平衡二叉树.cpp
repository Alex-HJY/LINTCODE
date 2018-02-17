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
	* @param root: The root of binary tree.
	* @return: True if this Binary tree is Balanced, or false.
	*/
	bool isBalanced(TreeNode * root) {
		// write your code here
		int i = getdepth(root);
		if (i >= 0) return true;
		return false;
	}
	int getdepth(TreeNode *root) {
		if (root == NULL) { return 0; }
		int i = getdepth(root->left);
		int j = getdepth(root->right);
		if (i == -1) return -1;
		if (j == -1) return -1;
		if (abs(i - j) <= 1) return max(i, j) + 1;
		return -1;
	}
};