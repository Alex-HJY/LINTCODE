class Solution {
public:
	/*
	* @param board: board a 2D board containing 'X' and 'O'
	* @return: nothing
	*/
	void dfs(int i, int j, vector<vector<char>> &map) {
		if ((i < 0) || (j < 0) || (i >= map.size()) || (j >= map[0].size())) { return; }
		if (map[i][j] != 'O') return;
		map[i][j] = '*';
		dfs(i - 1, j, map);
		dfs(i, j - 1, map);
		dfs(i + 1, j, map);
		dfs(i, j + 1, map);
	}
	void surroundedRegions(vector<vector<char>> &map) {
		// write your code here
		int la = map.size();
		if (la == 0) return;
		int lb = map[0].size();
		for (int i = 0; i < lb; i++) {
			dfs(0, i, map);
			dfs(la - 1, i, map);
		}
		for (int i = 0; i < la; i++) {
			dfs(i, 0, map);
			dfs(i, lb - 1, map);
		}
		for (int i = 0; i < la; i++) {
			for (int j = 0; j < lb; j++) {
				if (map[i][j] == 'O') map[i][j] = 'X';
				if (map[i][j] == '*') map[i][j] = 'O';
			}
		}
	}
};
