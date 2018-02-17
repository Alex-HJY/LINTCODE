class Solution {
public:
	/*
	* @param : a string to be split
	* @return: all possible split string array
	*/
	int l = 0;
	void dfs(string &s, int num, vector<string> t, vector<vector<string>> &ans) {
		if (num == l) {
			ans.push_back(t);
		}
		else {
			if ((l - num) >= 1) {
				t.push_back(s.substr(num, 1));
				dfs(s, num + 1, t, ans);
				t.pop_back();

			}
			if ((l - num) >= 2) {
				t.push_back(s.substr(num, 2));
				dfs(s, num + 2, t, ans);
				t.pop_back();
			}
		}
	}
	vector<vector<string>> splitString(string& s) {
		// write your code here
		l = s.length();
		vector<vector<string>> ans;
		vector<string> t;
		if (l > 1) {
			dfs(s, 0, t, ans);
		}
		else
		{
			if (l == 1)
				t.push_back(s);
			ans.push_back(t);
		}
		return ans;
	}
};
