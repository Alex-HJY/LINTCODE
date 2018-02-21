class Solution {
public:
	static bool cmp(int a, int b) {
		return a < b;
	}
	/*
	* @param numbers: Give an array numbers of n integer
	* @return: Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int>> threeSum(vector<int> &numbers) {
		// write your code here
		int l = numbers.size();
	//	unordered_set<vector<int>> anss;
		vector<vector<int>> ans;
		sort(numbers.begin(), numbers.end(), cmp);
		for (int i = 0; i < l; i++)		{
			for (int j = i + 1; j < l; j++) {
				int tt = numbers[i] + numbers[j];
				if (tt > 0) break;
				for (int k = j + 1; k < l; k++) {
					int t = numbers[i] + numbers[j] + numbers[k];
					if (t > 0) break;
					if (!t) {
						vector<int> temp;
						temp.push_back(numbers[i]);
						temp.push_back(numbers[j]);
						temp.push_back(numbers[k]);
						bool flag = false;
						for (int ttt = 0; ttt < ans.size(); ttt++) {
							if ((numbers[i]==ans[ttt][0]) && (numbers[j] == ans[ttt][1]) && (numbers[k] == ans[ttt][2]))
								flag = 1;
						}
						if (flag) break;	
							ans.push_back(temp);		
					}
				}
			}
		}
		return ans;
	}
};