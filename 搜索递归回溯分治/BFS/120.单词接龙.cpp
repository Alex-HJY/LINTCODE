class Solution {
public:
	/*
	* @param start: a string
	* @param end: a string
	* @param dict: a set of string
	* @return: An integer
	*/
	int ladderLength(string &start, string &end, unordered_set<string> &dict) {
		// write your code here
		if (start.empty() || end.empty() || dict.empty()) return 0;
		if (start.length() != end.length()) return 0;
		if (!strcmp(start.c_str(), end.c_str())) return 1;
		int ans = 1;
		queue<string> q;
		queue<int> val;
		q.push(start);
		val.push(1);

		while (!q.empty()) {
			string temp = q.front();
			int t = val.front();
			for (int i = 0; i < temp.length(); i++) {
				temp = q.front();
				for (int j = 'a'; j <= 'z'; j++) {
					if (temp[i] == j) continue;
					temp[i] = j;
					if (!strcmp(temp.c_str(), end.c_str())) {
						return ans = t + 1;
					}
					if (dict.find(temp) != dict.end()) {
						q.push(temp);
						val.push(t + 1);
						dict.erase(temp);
					}
				}
			}
			q.pop();
			val.pop();
		}
		return ans;

	}



};