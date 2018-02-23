class Solution {
public:
	/*
	* @param headA: the first list
	* @param headB: the second list
	* @return: a ListNode
	*/
	ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
		// write your code here
		ListNode *endb = headB;
		ListNode *enda = headA;
		int lena = 0, lenb = 0;
		if (!headA)
			return NULL;
		if (!headB)
			return NULL;
		while (enda->next)
		{
			++lena;
			enda = enda->next;
		}
		while (endb->next)
		{
			++lenb;
			endb = endb->next;
		}
		if (enda != endb)
			return NULL;

		while (lena > lenb) {
			--lena;
			headA = headA->next;
		}
		while (lena < lenb) {
			--lenb;
			headB = headB->next;
		}
		while (headB != headA) {
			headA = headA->next;
			headB = headB->next;

		}
		return headB;



	}
};
