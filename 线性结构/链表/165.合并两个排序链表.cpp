class Solution {
public:
	/*
	* @param l1: ListNode l1 is the head of the linked list
	* @param l2: ListNode l2 is the head of the linked list
	* @return: ListNode head of linked list
	*/
	ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
		// write your code here
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *p,*pp,*ans;
		p = new ListNode(0);
		ans = p;
		while(p1&&p2)
		{
			if (p1->val<p2->val)
			{
				pp = new ListNode(p1->val);
				p->next = pp;
				p = p->next;
				p1 = p1->next;
			}
			else
			{
				pp = new ListNode(p2->val);
				p->next = pp;
				p = p->next;
				p2 = p2->next;
			}
		}
		while (p1)
		{
				pp = new ListNode(p1->val);
				p->next = pp;
				p = p->next;
				p1 = p1->next;
		}
		while (p2)
		{
				pp = new ListNode(p2->val);
				p->next = pp;
				p = p->next;
				p2 = p2->next;
			}
		
		return ans->next;
	}
};