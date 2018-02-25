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
	* @return: Level order a list of lists of integer
	*/
	queue<TreeNode*> q;
	queue<int> level;
	vector<vector<int>> ans;

	vector<vector<int>> levelOrderBottom(TreeNode * root) {
		// write your code here
		if (root) {
			q.push(root);
			level.push(0);

			while (!q.empty()) {
				TreeNode *node = q.front();
				q.pop();
				int t = level.front();
				level.pop();

				if (ans.size() < t + 1) {
					vector<int> ttt;
					ans.push_back(ttt);
				}
				ans[t].push_back(node->val);
				if (node->left) {
					q.push(node->left);
					level.push(t + 1);
				}
				if (node->right) {
					q.push(node->right);
					level.push(t + 1);
				}
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};