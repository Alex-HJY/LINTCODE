#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	/*
	* @param s: A string
	* @return: A string
	*/
	string reverseWords(string &s) {
		// write your code here
		stack<string> ss;
		string ans = "", t = "";
		if (s != "") {
			s = s + ' ';
			int begin = 0;
			while (s[begin] == ' ') { ++begin; }
			//predo
			for (int i = begin; i < s.length(); i++) {
				if (s[i] != ' ') {
					t = t + s[i];
				}
				else
				{
					ss.push(t);
					t = "";
					while ((i < s.length() - 1) && (s[i + 1] == ' ')) {
						++i;
					}
				}
			}
			if (!ss.empty())
			{
				ans = ss.top();
				ss.pop();
			}
			while (!ss.empty()) {
				ans = ans + ' ' + ss.top();
				ss.pop();
			}
		}
		return ans;
	}
};


int main() {
	return 0;
	Solution s;
	string sss = "sadas dsa  saa  as   ";
	cout << s.reverseWords(sss)<< endl;
	system("pause");


}


