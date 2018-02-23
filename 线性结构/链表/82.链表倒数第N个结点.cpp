class Solution {
public:
	/*
	* @param head: The first node of linked list.
	* @param n: An integer
	* @return: Nth to last node of a singly linked list.
	*/
	int temp;
	ListNode *ans;
	int dfs(ListNode *node) {
		if (!node)
			return 0;
		else {
			int t = 1 + dfs(node->next);
			if (t == temp)
				ans = node;
			return t;
		}
	}
	ListNode * nthToLast(ListNode * head, int n) {
		// write your code here
		temp = n;
		dfs(head);
		return ans;

	}
};
