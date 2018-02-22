class Solution {
public:
	/**
	* @param grid: a list of lists of integers
	* @return: An integer, minimizes the sum of all numbers along its path
	*/
	int minPathSum(vector<vector<int>> &grid) {
		// write your code here
		int m = grid.size();
		if (!m) return  0;
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
		dp[0][0] = grid[0][0];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i - 1 >= 0)
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
				if (j - 1 >= 0)
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
			}
		}
		return dp[m - 1][n - 1];

	}
};