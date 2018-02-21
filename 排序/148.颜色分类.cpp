class Solution {
public:
	/**
	* @param nums: A list of integer which is 0, 1 or 2
	* @return: nothing
	*/
	void Qsort(vector<int> &a, int low, int high) {
		if  (low < high) {
			int first = low;
			int last = high;
			int key = a[first];
			while (first<last) {
				while ((first < last) && (a[last] >= key)) {
					--last;
				}
				a[first] = a[last];
				while ((first < last) && (a[first] <= key)) {
					++first;
				}
				a[last] = a[first];
			}
			a[first] = key;
		Qsort(a, first+ 1, high);
			Qsort(a, low, first-1);
		}
	}
	void sortColors(vector<int> &nums) {
		// write your code here
		Qsort(nums,0,nums.size()-1);
	}
};