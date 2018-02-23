class Solution {
public:
	/**
	* @param prices: Given an integer array
	* @return: Maximum profit
	*/
	int maxProfit(vector<int> &prices) {
		// write your code here
		queue<int> q;
		int ans = 0;
		int l = prices.size();
		for (int i = 0; i < l; i++)
		{
			q.push(prices[i]);
			while (!q.empty() && q.front()>prices[i])
			{
				q.pop();
			}
			ans = max(ans, prices[i] - q.front());
		}
		return ans;
	}
};