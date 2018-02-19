class Solution {
public:
	/**
	* @param n: An integer
	* @return: An integer
	*/
	int numTrees(int n) {
		// write your code here
		int *d = new int[n + 1];
		d[0] = 1;
		d[1] = 1;
		for (int i = 2; i <= n; i++) {
			int t = 0;
			for (int j = 0; j < i; j++) {
				t += d[j] * d[i - 1 - j];
			}
			d[i] = t;
		}
		return d[n];
	}
};

