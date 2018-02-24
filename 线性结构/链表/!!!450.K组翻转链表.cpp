class Solution {
public:
	/*
	* @param head: a ListNode
	* @param k: An integer
	* @return: a ListNode
	*/
	ListNode *temp;
	ListNode *ans;
	ListNode *dfs(ListNode *node, int n)
	{
		if (!node) return NULL;
		--n;
		if (n > 0) {
			ListNode *k = dfs(node->next, n);
			if (k) {
				k->next = node;
			}
			else {
				return NULL;
			}
		}
		else {

			temp = node->next;
			ans = node;
		}
		return node;
	}
	ListNode * reverseKGroup(ListNode * head, int k) {
		// write your code here
		temp = head;
		if (k == 1)
			return head;
		ListNode *ii, *jj, *kk;
		ii = new ListNode(3);
		jj = NULL;
		while (head) {
			temp = NULL;
			//   ii->next=ans;
			kk = dfs(head, k);
			if (jj == NULL) jj = ans;
			ii->next = ans;
			if (!kk) {
				break;
			}
			else {
				ii = kk;
			}
			head = temp;

		}
		ii->next = head;
		return  jj;
	}
};