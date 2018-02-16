class Solution {
public:
	/*
	* @param source: source string to be scanned.
	* @param target: target string containing the sequence of characters to match
	* @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
	*/
	bool cmp(int begin, string s, string t) {
		for (int i = 0; i < t.length(); i++) {
			if (t[i] != s[begin + i])
				return false;
		}

		return true;
	}
	int strStr(const char *source, const char *target) {
		// write your code here
		if (source==NULL) { return -1; }
		if (target== NULL) { return -1; }
		int ans = -1;
		string s = source;
		string t = target;
		int ls = s.length();
		int lt = t.length();
		if (ls < lt) { return -1; }
		if (ls <=0) { return 0; }
		if (lt <=0) { return 0; }
		for (int i = 0; i <= ls - lt; i++) {
			if (s[i] == t[0]) {
				if (cmp(i, s, t)) {
					return i;
				}
			}
		}

		cout << s << endl;

		return -1;
	}
};
