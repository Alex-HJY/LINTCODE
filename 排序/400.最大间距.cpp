class Solution {
public:
	/**
	* @param nums: an array of integers
	* @return: the maximun difference
	*/
	static bool cmp(int a, int b) {
		return a <= b;
	}
	int maximumGap(vector<int> &nums) {
		// write your code here
		int ans= 0;
		int l = nums.size();
		if (l < 2) return 0;
				sort(nums.begin(), nums.end(), cmp);
		for (int i = 0; i < l - 1; i++) {
			ans = max(ans, nums[i + 1] - nums[i]);
		}
		return ans;
	}
};