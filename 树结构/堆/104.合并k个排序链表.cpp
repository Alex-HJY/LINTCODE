class min_heap
{
public:
	vector<int>	data;
	min_heap() {}
	min_heap(vector<int> source)
	{
		for (int i = 0; i < source.size(); ++i)
		{
			push(source[i]);
		}
	}
	void up(int n) {
		for (int i = n; i>0; i = (i - 1) / 2)
		{
			if (data[(i - 1) / 2] > data[i]) swap(data[(i - 1) / 2], data[i]);
			else { break; }
		}

	}
	void down(int n)
	{
		while (n * 2 + 1 <= (data.size() - 1))
		{
			if (n * 2 + 2>data.size() - 1)
			{
				if (data[n * 2 + 1]<data[n])
				{
					swap(data[n * 2 + 1], data[n]);
					n = n * 2 + 1;
				}
				else { break; }
			}
			else
			{
				int d1 = data[n * 2 + 1];
				int d2 = data[n * 2 + 2];
				if (d1 >= data[n] && d2 >= data[n])
				{
					break;
				}
				else
				{
					int t = min(d1, d2);
					if (t == d1)
					{
						swap(data[n * 2 + 1], data[n]);
						n = n * 2 + 1;
					}
					else
					{
						swap(data[n * 2 + 2], data[n]);
						n = n * 2 + 2;
					}
				}
			}
		}

	}

	void push(int k)
	{
		data.push_back(k);
		up(data.size() - 1);
	}
	int pop()
	{
		int t = data[0];
		swap(data[0], data[data.size() - 1]);
		data.pop_back();
		if (data.size())
			down(0);
		return t;
	}


};

class Solution {
public:
	/**
	* @param lists: a list of ListNode
	* @return: The head of one sorted list.
	*/
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		// write your code here
		ListNode *ans, *t;
		min_heap heap;
		int m = lists.size();
		if (!m) { return NULL; }
		for (int i = 0; i < m; ++i)
		{

			t = lists[i];
			while (t)
			{
				cout << t->val << "  1" << endl;
				heap.push(t->val);
				t = t->next;
			}
		}
		if (!heap.data.size()) return NULL;
		t = new ListNode(heap.data[0]);
		t->next = NULL;
		ans = t;
		cout << "1" << endl;
		int k = heap.data.size();
		for (int i = 0; i < k; ++i)
		{
			cout << "1" << endl;
			t->next = new ListNode(heap.data[0]);
			heap.pop();

			t = t->next;
		}

		return ans->next;
	}
};