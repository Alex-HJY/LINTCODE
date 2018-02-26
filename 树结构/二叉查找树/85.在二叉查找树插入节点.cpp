
class Solution {
public:
	/*
	* @param root: The root of the binary search tree.
	* @param node: insert this node into the binary search tree
	* @return: The root of the new binary search tree.
	*/
	void insert(TreeNode *node)
	{
		if (p->val>node->val)
		{
			if (!node->right)
			{
				node->right = p;
			}
			else
			{
				insert(node->right);
			}
		}
		else
		{
			if (!node->left)
			{
				node->left = p;
			}
			else
			{
				insert(node->left);
			}
		}
		return;
	}
	TreeNode *p, *t;
	TreeNode * insertNode(TreeNode * root, TreeNode * node) {
		// write your code here]
		if (!root) return node;
		p = node;
		insert(root);
		return  (root);

	}
};
