#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;



class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


class Solution {
public:
	/*
	* @param root: a TreeNode, the root of the binary tree
	* @return:
	*/
	TreeNode *dfs(TreeNode *node) {
		if ((!node->left) && (!node->right)) return node;
		TreeNode *l = node->left;
		TreeNode *r = node->right;
		TreeNode *temp;
		if (l) {
			temp = dfs(l);
			node->right = l;
			temp->right = r;
		}
		node->left= NULL;
		if (r) {
			return dfs(r);
		}
		return (temp);

	}
	void flatten(TreeNode * root) {
		// write your code here
		if (root) {
			dfs(root);
		}
	}
};

int main() {

	return 0;
}


