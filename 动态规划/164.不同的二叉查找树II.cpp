class Solution {
public:
	/**
	* @paramn n: An integer
	* @return: A list of root
	*/
	int maxn;
	vector<TreeNode *> dfs(int low, int high) {
		vector<TreeNode* > temp;
		if (low > high) {
			temp.push_back(NULL);
			return temp;
		}



		for (int i = low; i <= high; i++) {
			vector<TreeNode* > left = dfs(low, i - 1);
			vector<TreeNode* > right = dfs(i + 1, high);
			int ll = left.size();
			int lr = right.size();
			for (int j = 0; j < ll; j++) {
				for (int k = 0; k < lr; k++) {
					TreeNode *p = new TreeNode(i);
					p->left = left[j];
					p->right = right[k];
					temp.push_back(p);
				}
			}

		}
		return temp;
	}
	vector<TreeNode *> generateTrees(int n) {
		// write your code here
		vector<TreeNode *> ans = dfs(1, n);
		return ans;
	}
};