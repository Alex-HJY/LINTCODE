class Solution {
public:
	/*
	* @param : A string
	* @param : A string
	* @return: Count the number of distinct subsequences
	*/
	int numDistinct(string S, string T) {
		// write your code here
		int sizeS = S.size(), sizeT = T.size(), i = 0, j = 0;
		if ((sizeS <= 0) || (sizeT <= 0)) {
			return 1;
		}
		vector<int> dp(sizeT + 1, 0);
		dp[0] = 1;
		for (i = 1; i <= sizeS; i++) {
			for (j = min(sizeT, i); j > 0; j--) {
				if (S[i - 1] == T[j - 1]) {
					dp[j] += dp[j - 1];
				}
			}
		}
		return dp[sizeT];

	}
};
