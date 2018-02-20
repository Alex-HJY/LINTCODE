class Solution {
public:
	/*
	* @param head: The first node of linked list.
	* @return: The head of linked list.
	*/
	ListNode * insertionSortList(ListNode * head) {
		// write your code here
		ListNode *temp;
		if (!head) return NULL;
		if (!head->next) return head;
		temp = head;
		ListNode *ans = new ListNode(-INT_MAX);
		while (head) {
			temp = ans;
			while (temp) {
				if (!temp->next) {
					temp->next = new ListNode(head->val); break;
				}
				else {
					if (head->val > temp->next->val) {
						temp = temp->next;
					}
					else {
						ListNode *t = new ListNode(head->val);
						t->next = temp->next;
						temp->next = t; break;
					}
				}
			}
			head = head->next;
		}

		return ans->next;
	}
};