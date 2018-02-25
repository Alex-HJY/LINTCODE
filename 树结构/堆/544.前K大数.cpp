class max_heap
{
public:
	vector<int>	data;
	max_heap(vector<int> source)
	{
		for (int i = 0; i < source.size(); ++i)
		{
			push(source[i]);
		}
	}
	void up(int n){
		for(int i=n;i>0;i=(i-1)/2)
		{
			if (data[(i - 1) / 2] < data[i]) swap(data[(i - 1) / 2], data[i]);
			else { break; }
		}

	}
	void down(int n)
	{
		while (n*2+1<=(data.size()-1))
		{
			if (n*2+2>data.size()-1)
			{
				if (data[n*2+1]>data[n])
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
				if (d1<=data[n]&&d2<=data[n])
				{
					break;
				}else 
				{
					int t = max(d1, d2);
					if (t==d1)
					{
						swap(data[n * 2 + 1], data[n]);
						n = n * 2 + 1;
					}else
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

		down(0);

		return t;
	}
	
	
};

class Solution {
public:
	/**
	* @param nums: an integer array
	* @param k: An integer
	* @return: the top k largest numbers in array
	*/
	vector<int> topk(vector<int> &nums, int k) {
		// write your code here
		vector<int> ans;
		if (nums.size() == 0) return ans;
		max_heap heap(nums);
		for (int i = 0; i < k; ++i)
		{
			ans.push_back(heap.pop());
		}
		return ans;
	}
};
