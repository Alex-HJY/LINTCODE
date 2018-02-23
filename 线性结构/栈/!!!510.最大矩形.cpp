class Solution {
public:
	/*
	* @param matrix: a boolean 2D matrix
	* @return: an integer
	*/
	int maximalRectangle(vector<vector<bool>> &matrix) {
		// write your code here
		int m = matrix.size();
		if (m == 0)
		{
			return 0;
		}
		int n = matrix[0].size();
		vector<vector<int>> map;
		for (int i = 0; i < m; i++)
		{
			vector<int> temp;
			for (int j = 0; j < n; j++)
			{
				temp.push_back((int)matrix[i][j]);
			}
			temp.push_back(0);
			map.push_back(temp);
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j])
					map[i][j] += map[i - 1][j];

			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			stack<int> s;
			for (int j = 0; j <= n; j++)
			{
				while ((!s.empty()) && (map[i][s.top()]>map[i][j]))
				{
					int t = s.top();
					s.pop();
					int temp = s.empty() ? j : j - s.top() - 1;
					ans = max(ans, map[i][t] * temp);

				}
				s.push(j);
			}
		}
		return ans;
	}
};
