
class Solution {
public:
	static bool cmp(int a, int b) {
		return a < b;
	}
	/*
	* @param numbers: Give an array numbers of n integer
	* @return: Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int>> fourSum(vector<int> &numbers, int target) {
		// write your code here
		int l = numbers.size();
		set<vector<int>> anss;
		//	unordered_set<vector<int>> anss;
		vector<vector<int>> ans;
	
		sort(numbers.begin(), numbers.end(), cmp);
		for (int i = 0; i < l; i++) {
			for (int j = i + 1; j < l; j++) {
				int tt = numbers[i] + numbers[j];
				int k = j+1;
				int kk = l-1;
				while(k <kk) {
		
			
						int t = numbers[i] + numbers[j] + numbers[k] + numbers[kk];
						
						if (target == t) {
							vector<int> temp;
							temp.push_back(numbers[i]);
							temp.push_back(numbers[j]);
							temp.push_back(numbers[k]);
							temp.push_back(numbers[kk]);
							anss.insert(temp);
								++k;
							--kk;
						}
						if (t < target) ++k;
						if (t > target) --kk;
				}
	
			}
		}
		set<vector<int>>::iterator it;
		for (it = anss.begin(); it != anss.end(); it++) {
			ans.push_back(*it);
		}
		return ans;
	}
};
