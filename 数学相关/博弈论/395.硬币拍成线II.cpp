class Solution {
public:
	/*
	* @param values: a vector of integers
	* @return: a boolean which equals to true if the first player will win
	*/
	bool firstWillWin(vector<int> &values) {
		int l = values.size();
		if (l<=2) return true;
        if (l==3){
				if ((values[0]+values[1])>values[2])return true;
				return false;
			}
		vector<int> dp;
		int sum=0;
		for (int i = 0; i <= l; i++) {
			if (i!=l)		
			sum = sum + values[i];
			dp.push_back(0);
		}
		dp[l - 1] = values[l - 1];
		dp[l - 2] = values[l - 1] + values[l - 2];
		dp[l - 3] = values[l - 2] + values[l - 3];
		for (int i = l - 4; i >= 0; i--) {
			int t=values[i]+values[i+1]+min(dp[i+3],dp[i+4]);
			int tt = values[i]  + min(dp[i + 2], dp[i + 3]);
			dp[i] = max(t, tt);
		}
		cout<<dp[0]<<endl;
		if ((dp[0]) > (sum - dp[0]))
			return true;
		return false;
		
		// write your code here
	}
};
