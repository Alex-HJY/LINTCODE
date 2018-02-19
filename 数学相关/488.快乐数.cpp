class Solution {
public:
	/**
	* @param n: An integer
	* @return: true if this is a happy number or false
	*/
	unordered_set<int> set;
	bool isHappy(int n) {
		// write your code here
		if (n == 1)return 1;
		while (n != 1) {
			string s = to_string(n);
			int ans = 0;
			for (int i = 0; i < s.size(); i++) {
				int t = (int)(s[i] - '0');
				t = t*t;
				ans += t;
			}
			if (set.find(ans) != set.end()) {
				return 0;
			}
			else
			{
				set.insert(ans);
				n = ans;
			}
		}
		return true;
	}
};
