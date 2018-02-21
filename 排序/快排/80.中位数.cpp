class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer denotes the middle number of the array
	*/
	void Qsort(vector<int> &a, int low, int high) {
		if (low >= high) {
			return;
		}
		int first = low;
		int last = high;
		int key = a[first];
		while (first < last) {
			while ((first < last) && (a[last] >= key)) { --last; }
			a[first] = a[last];
			while ((first < last) && (a[first] <= key)) { ++first; }
			a[last] = a[first];
		}
		a[first] = key;
		Qsort(a, low, first - 1);
		Qsort(a, first + 1, high);
	}

	int median(vector<int> &nums) {
		// write your code here
		Qsort(nums, 0, nums.size() - 1);
		if (nums.size() %2== 1) {
			return nums[nums.size() / 2];
		}
		else {
			return nums[nums.size() / 2-1];
		}

	}
};