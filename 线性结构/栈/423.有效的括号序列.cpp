class Solution {
public:
	/**
	* @param s: A string
	* @return: whether the string is a valid parentheses
	*/
	bool isValidParentheses(string &s) {
		// write your code here
		stack<char> ss;
		int l = s.size();
		for (int i = 0; i < l; i++) {
			char c = s[i];
			if (c == '(' || c == '{' || c == '[')
				ss.push(c);
			if (c == ')') {
				if (ss.empty()) return false;
				if (ss.top() == '(') {
					ss.pop();
				}
				else
				{
					return false;
				}
			}
			if (c == ']') {
				if (ss.empty()) return false;
				if (ss.top() == '[') {
					ss.pop();
				}
				else
				{
					return false;
				}
			}
			if (c == '}') {
				if (ss.empty()) return false;
				if (ss.top() == '{') {
					ss.pop();
				}
				else
				{
					return false;
				}
			}



		}
		return ss.empty();
	}
};