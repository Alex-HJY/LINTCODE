class Solution {
public:
	/**
	* @param A: The prices [i]
	* @param k:
	* @return: The ans array
	*/
	vector<int> price, ans;
	int getmaxprice(SegmentTreeNode * root, int start, int end) {
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
			return getmaxprice(root->right, start, end);
		}
		if (end <= mid)
		{
			return  getmaxprice(root->left, start, end);
		}
		return min(getmaxprice(root->left, start, mid), getmaxprice(root->right, mid + 1, end));
	}

	void build(SegmentTreeNode *node)
	{
		if (node->start >= node->end)
		{
			node->max = price[node->start];
			return;
		}
		int start = node->start;
		int end = (node->start + node->end) / 2;
		node->left = new SegmentTreeNode(start, end, 0);
		build(node->left);
		start = (node->start + node->end) / 2 + 1;
		end = node->end;
		node->right = new SegmentTreeNode(start, end, 0);
		build(node->right);
		node->max = min(node->left->max, node->right->max);
	}

	vector<int> business(vector<int> &A, int k) {
		// Write your code here
		price = A;
		SegmentTreeNode *root = new SegmentTreeNode(0, A.size() - 1, 0);
		build(root);
		int l = A.size();
		for (int i = 0; i < l; ++i)
		{
			ans.push_back(max(-(getmaxprice(root, i - k, i + k) - price[i]), 0));
		}
		return ans;
	}
};