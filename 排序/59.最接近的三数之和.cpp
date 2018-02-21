class Solution {
public:
	static bool cmp(int a, int b) {
		return a < b;
	}
	/*
	* @param numbers: Give an array numbers of n integer
	* @return: Find all unique triplets in the array which gives the sum of zero.
	*/
	int threeSumClosest(vector<int> &numbers, int target) {
		int ans = 10000000;
		int l = numbers.size();
		sort(numbers.begin(), numbers.end(), cmp);
		for (int i = 0; i < l - 2; i++) {
			int k = i + 1;
			int kk = l - 1;
			while (k < kk) {


				int t = numbers[i] + numbers[k] + numbers[kk];

				if (target == t) {
					return target;
					++k;
					--kk;
				}
				if (t < target) {
					++k;
					if (abs(t - target) < abs(ans - target)) {
						ans = t;
					}
				}
				if (t > target) {
					--kk;
					if (abs(t - target) < abs(ans - target)) {
						ans = t;
					}
				}

			}
		}
		return ans;
	}
};