class Solution {
public:
	/*
	* @param num: a positive number
	* @return: true if it's a palindrome or false
	*/
	bool isPalindrome(int num) {
		// write your code here
		string s, t = "";
		s = to_string(num);
		for (int i = 0; i<s.length(); i++)
		{
			t = s[i] + t;
		}
		//	cout << s.c_str() << " " << t.c_str() << endl;
		return !strcmp(s.c_str(), t.c_str());
	}
};

