class Solution {
public:
	/**
	* @param s: A string
	* @return: Whether the string is a valid palindrome
	*/
	bool isPalindrome(string &s) {
		// write your code here
		if (s.empty())	return 1;
		string t, tt = "";
		for (int i = 0; i < s.length(); i++) {
			if (isalnum(s[i]))
				tt += tolower(s[i]);
		}
		t = tt;
		reverse(t.begin(), t.end());

		return !strcmp(tt.c_str(), t.c_str());
	}
};