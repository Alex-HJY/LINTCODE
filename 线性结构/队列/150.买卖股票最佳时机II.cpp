class Solution {
public:
	/**
	* @param prices: Given an integer array
	* @return: Maximum profit
	*/
	int maxProfit(vector<int> &prices) {
		// write your code here
		int ans = 0;
		queue<int> q;
		prices.push_back(0);
		int l = prices.size();
		for (int i = 0; i < l; i++)
		{
			if (!q.empty()) {
				if (prices[i] < q.back()) {
					ans += q.back() - q.front();
					while (!q.empty())
					{
						q.pop();
					}
				}
			}
			q.push(prices[i]);
		}
		return ans;
	}
};
