
struct cmp1 {
	bool operator ()(Interval &a, Interval &b) {
		return a.end < b.end;
		// write your code here
	}
};
int KK;
void dfs(int k, set<int> &relate, vector<vector<int>> &G)
{
	for (int i = 0; i < G[k].size(); ++i)
	{
		if (relate.find(G[k][i]) == relate.end() && G[k][i] != KK)
		{
			relate.insert(G[k][i]);
			dfs(G[k][i], relate, G);
		}
	}
}
class Solution {
public:
	/**
	* @param rating: the rating of the movies
	* @param G: the realtionship of movies
	* @param S: the begin movie
	* @param K: top K rating
	* @return: the top k largest rating moive which contact with S
	*/
	vector<int> topKMovie(vector<int> &rating, vector<vector<int>> &G, int S, int K) {
		priority_queue <Interval, vector<Interval>, cmp1> q;
		KK = S;
		vector<int> ans;
		set<int> relate;
		int m = G.size();
		if (!m) return  ans;
		cout << K << "K " << S << "S " << endl;
		for (int i = 0; i < m; ++i)
		{
			int n = G[i].size();
			for (int j = 0; j < n; ++j)
			{
				G[G[i][j]].push_back(i);
			}
		}
		dfs(S, relate, G);
		for (auto it = relate.begin(); it != relate.end(); ++it)
		{
			Interval temp(*it, rating[*it]);
			q.push(temp);
		}
		int tt = q.size();
		for (int i = 0; i < min(tt, K); ++i)
		{
			Interval temp = q.top();
			cout << temp.start << " ";
			ans.push_back(temp.start);
			q.pop();
		}
		return  ans;
		// Write your code here
	}
};
