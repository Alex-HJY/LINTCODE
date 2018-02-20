class Solution {
public:
	/*
	* @param nums: A list of non negative integers
	* @return: A string
	*/
	static bool cmp(int aa, int bb) {
		string a = to_string(aa);
		string b = to_string(bb);
		int la = a.size();
		int lb = b.size();
		int lmax = max(la, lb);
		int lmin = max(la, lb);
		for (int i = la;i < lmax; i++) {
			a = a + a[0];
		}
		for (int i = lb; i < lmax; i++) {
			b = b + b[0];
		}
		return a > b;
	}
	string largestNumber(vector<int> &nums) {
		// write your code here
		string ans;
		if (!nums.size()) return ans;
		sort(nums.begin(), nums.end(), cmp);
		for (int i = 0; i < nums.size(); i++) {
			ans = ans + to_string(nums[i]);
		}
		if (ans[0]=='0') return "0";
		return ans;
	}
};
