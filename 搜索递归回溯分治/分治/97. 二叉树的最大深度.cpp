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
	/**
	* @param root: The root of binary tree.
	* @return: An integer
	*/
	int maxDepth(TreeNode *root) {
		// write your code here
		if (root == NULL) return 0;
		int i = 0, j = 0;
		i = maxDepth(root->left);
		j = maxDepth(root->right);
		return max(i, j) + 1;
	}
};