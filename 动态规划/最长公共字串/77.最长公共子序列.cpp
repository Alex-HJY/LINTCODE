
class Solution {
public:
	/**
	* @param A: A string
	* @param B: A string
	* @return: The length of longest common subsequence of A and B
	*/
	int longestCommonSubsequence(string &A, string &B) {
		// write your code here
		int la = A.length();
		int lb = B.length();
		if (!la) return 0;
		if (!lb) return 0;
		int **d = new int *[la + 2];
		for (int i = 0; i <= la; i++) {
			d[i] = new int[lb + 2];
		}
		A = " " + A;
		B = " " + B;
		for (int i = 0; i <= la; i++) {
			memset(d[i], 0, sizeof(d[i]));
		}
		for (int i = 1; i <= la; i++) {
			for (int j = 1; j <= lb; j++) {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
				if (A[i] == B[j]) {
					d[i][j] = max(d[i][j], d[i - 1][j - 1] + 1);
				}
			}
		}
		return d[la][lb];
	}
};