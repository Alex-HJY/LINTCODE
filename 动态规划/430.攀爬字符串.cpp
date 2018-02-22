class Solution {
public:
	/**
	* @param s1: A string
	* @param s2: Another string
	* @return: whether s2 is a scrambled string of s1
	*/
	bool isScramble(string &s1, string &s2) {
		// write your code here
		int la = s1.size();
		int lb = s2.size();
		if (la != lb) return false;
		int n = la;
		vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n, false)));
		for (int k = 1; k <= n; k++) {
			for (int i = 0; i <= n - k; i++) {
				for (int j = 0; j <= n - k; j++) {
					if (k == 1) {
						if (s1[i] == s2[j]) dp[i][j][k] = 1;
					}
					else
					{
						for (int t = 1; t < k; t++) {
							if (((dp[i][j][t]) && (dp[i + t][j + t][k - t])) || ((dp[i][j + k - t][t]) && (dp[i + t][j][k - t])))
							{
								dp[i][j][k] = true;
								break;
							}
						}
					}
				}
			}
		}
		return dp[0][0][n];
	}
};