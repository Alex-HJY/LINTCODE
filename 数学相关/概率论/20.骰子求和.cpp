class Solution {
public:
	/**
	* @param n an integer
	* @return a list of pair<sum, probability>
	*/
	vector<pair<int, double>> dicesSum(int n) {
		// Write your code here
		vector<pair<int, double>> ans;
		double p = 1.0 / 6;
		double **dp = new double*[n+1];
		for (int i = 0; i <= n; i++) {
			dp[i] = new double[6 * n + 1];
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <=6* n; j++) {
				dp[i][j] = 0;
			}
		}
		for (int i = 1; i <= 6; i++) {		dp[1][i] = p;		}

		for (int i = 1; i <= n - 1; i++) {
			for (int j = i; j <= 6 * i; j++) {
				for (int k = 1; k <= 6; k++) {
					dp[i + 1][j + k] += dp[i][j] * p;
				}
			}
		}
		for (int i = n; i <= 6*n; i++) {
			pair<int, double> t(i, dp[n][i]);
		//	cout << i<<" "<<dp[n][i] << endl;
			ans.push_back(t);
		}


		return ans;
	}
};