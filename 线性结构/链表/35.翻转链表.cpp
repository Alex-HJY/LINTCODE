class Solution {
public:
	/*
	* @param head: n
	* @return: The new head of reversed linked list.
	*/
	ListNode *ans;
	ListNode *dfs(ListNode *p) {
		if (!p->next) {
			ans = p;
			return p;
		}
		else {
			dfs(p->next)->next = p;
			return p;
		}
	}
	ListNode * reverse(ListNode * head) {
		// write your code here
		if (head)
			dfs(head)->next = NULL;
		return ans;
	}
};