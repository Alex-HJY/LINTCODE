#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

class Solution {
public:
	/*
	* @param root: The root of binary tree.
	* @return: True if this Binary tree is Balanced, or false.
	*/
	bool isBalanced(TreeNode * root) {
		// write your code here
		int i = getdepth(root);
		if (i>=0) return 1;
		return -1;
	}
	int getdepth(TreeNode *root) {
		if (root == NULL) { return 0; }
		int i = getdepth(root->left);
		int j = getdepth(root->right);
		if (i == -1) return -1;
		if (j == -1) return -1;
		if (abs(i-j)<=1) return max(i, j) + 1;
	}
};



int main() {
	return 0;
}


