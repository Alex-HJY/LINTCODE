class Solution {
public:
	/**
	* @param m: positive integer (1 <= m <= 100)
	* @param n: positive integer (1 <= n <= 100)
	* @return: An integer
	*/
	int uniquePaths(int m, int n) {
		// write your code here
		int d[101][101];
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				d[i][j] = 0;
			}
		}
		d[1][1] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = max(d[i][j], d[i - 1][j] + d[i][j - 1]);
			}
		}
		return d[m][n];
	}
};