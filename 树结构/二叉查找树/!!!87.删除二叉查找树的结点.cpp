class Solution {
public:
	/*
	* @param root: The root of the binary search tree.
	* @param value: Remove the node with given value.
	* @return: The root of the binary search tree after removal.
	*/


	TreeNode * removeNode(TreeNode * root, int value) {
		// write your code here
		if (root == NULL) return NULL;

		if (root->val>value)
		{
			root->left = removeNode(root->left, value);
			return root;
		}
		if (root->val<value)
		{
			root->right = removeNode(root->right, value);
			return root;
		}
		if ((!root->left) || (!root->right))
			root = (root->left != NULL) ? root->left : root->right;
		else
		{
			TreeNode *temp = root->right;
			while (temp->left)
			{
				temp = temp->left;
			}
			root->val = temp->val;
			root->right = removeNode(root->right, temp->val);
		}


		return root;
	}
};