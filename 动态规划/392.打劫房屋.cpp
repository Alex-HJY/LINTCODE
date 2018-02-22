class Solution {
public:
	/*
	* @param A: An array of non-negative integers
	* @return: The maximum amount of money you can rob tonight
	*/
	long long houseRobber(vector<int> &A) {
		// write your code here]
		// write your code here
		int n = A.size();
		if (!n) return 0;
		vector<long long> d1(n + 1, 0);
		vector<long long> d0(n + 1, 0);
		d1[1] = A[0];
		for (int i = 2; i <= n; i++) {
			long long t = (long long)A[i - 1];
			d1[i] = d0[i - 1] + t;
			d0[i] = max(d0[i - 1], d1[i - 1]);
		}
		return max(d1[n], d0[n]);
	}
};