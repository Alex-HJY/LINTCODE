class Solution {
public:
	/*
	* @param root: The root of segment tree.
	* @param start: start value.
	* @param end: end value.
	* @return: The maximum number in the interval [start, end]
	*/
	int query(SegmentTreeNode * root, int start, int end) {
		// write your code here
		if (end < start) return 0;
		if (end < root->start) return 0;
		if (start > root->end) return 0;
		start = max(start, root->start);
		end = min(end, root->end);
		if (start == root->start && end == root->end) return root->max;
		int mid = (root->start + root->end) / 2;
		if (start>mid)
		{
			return query(root->right, start, end);
		}
		if (end <= mid)
		{
			return  query(root->left, start, end);
		}
		return max(query(root->left, start, mid), query(root->right, mid + 1, end));
	}
};
