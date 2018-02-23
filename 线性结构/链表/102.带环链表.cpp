class Solution {
public:
	/*
	* @param head: The first node of linked list.
	* @return: True if it has a cycle, or false
	*/
	bool hasCycle(ListNode * head) {
		// write your code here
		set<ListNode *> s;
		if (head == NULL)
		{
			return false;
		}
		ListNode*p = head;

		while (p) {
			s.insert(p);
			p = p->next;
			if (p) {

				if (s.find(p) != s.end())
				{
					return true;
				}
			}
		}
		return false;
	}
};
