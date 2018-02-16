class Solution {
public:
	/*
	* @param s: A string
	* @return: the length of last word
	*/
	int lengthOfLastWord(string &s) {
		// write your code here
		int ans = 0;
		int l = s.length() - 1;
		while ((l >= 0) && (s[l] == ' ')) { --l; }
		if (l == -1) { return 0; }
		int t = l;
		while ((l >= 0) && s[l] != ' ') {
			--l;
			++ans;
		}
		//	cout << t << " " << ans << endl;
		return ans == (t - l) ? ans : 0;
	}
};
