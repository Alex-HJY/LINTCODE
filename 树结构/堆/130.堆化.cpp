class Solution {
public:
	/*
	* @param A: Given an integer array
	* @return: nothing
	*/
	void up(int n, vector<int> &data) {
		for (int i = n; i>0; i = (i - 1) / 2)
		{
			if (data[(i - 1) / 2] > data[i]) swap(data[(i - 1) / 2], data[i]);
			else { break; }
		}

	}
	void heapify(vector<int> &A) {
		// write your code here
		for (int i = 0; i <(int)A.size(); ++i)
		{
			up(i, A);
		}
		return;
	}
};
