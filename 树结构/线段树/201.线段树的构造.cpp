class Solution {
public:
	/*
	* @param start: start value.
	* @param end: end value.
	* @return: The root of Segment Tree.
	*/
	void dfs(SegmentTreeNode *node)
	{
		if (node->start >= node->end) return;
		int start = node->start;
		int end = (node->start + node->end) / 2;
		node->left = new SegmentTreeNode(start, end);
		dfs(node->left);
		start = (node->start + node->end) / 2 + 1;
		end = node->end;
		node->right = new SegmentTreeNode(start, end);
		dfs(node->right);
	}

	SegmentTreeNode * build(int start, int end) {
		// write your code here
		if (start >end) return NULL;
		SegmentTreeNode *root = new SegmentTreeNode(start, end);
		dfs(root);
		return root;
	}
};
