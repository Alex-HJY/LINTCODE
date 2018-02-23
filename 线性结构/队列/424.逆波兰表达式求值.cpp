class Solution {
public:
	/*
	* @param tokens: The Reverse Polish Notation
	* @return: the value
	*/
	int evalRPN(vector<string> &tokens) {
		// write your code here
		stack<int> s;
		int l = tokens.size();
		for (int i = 0; i < l; i++)
		{
			if (tokens[i] == "*")
			{
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(a*b);
			}
			else if (tokens[i] == "/")
			{
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(b / a);
			}
			else if (tokens[i] == "+")
			{
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(a + b);
			}
			else if (tokens[i] == "-")
			{
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(b - a);
			}
			else {
				int a = atoi(tokens[i].c_str());
				s.push(a);
			}
		}
		return s.top();
	}
};
