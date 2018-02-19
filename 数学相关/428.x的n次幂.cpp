class Solution {
public:
	/*
	* @param x: the base number
	* @param n: the power number
	* @return: the result
	*/
	double dfs(double x, int n) {
		// write your code here
		if ((n) == 1) return x;
		if ((n) == -1) return 1/x;
		double t = dfs(x, n / 2);
		t = t*t;
		if (n % 2>0 ) t = t*x;
		if (n % 2<0) t = t/x;
		return t;
	}
	double myPow(double x,int n) {
		// write your code here
		if (n == 0)return 1;
		double ans=dfs(x, n);
		return ans;
	}
};
