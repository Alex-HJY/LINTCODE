class Solution {
public:
	/*
	* @param matrix: matrix, a list of lists of integers
	* @param target: An integer
	* @return: a boolean, indicate whether matrix contains target
	*/
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		// write your code here
		const int m = matrix.size();
		if (!m) return  false;
		const int n = matrix[0].size();
		auto high = m - 1;
		auto low = 0;
		int mid = 0;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (matrix[mid][0] == target)
			{
				return true;
			}
			if (matrix[mid][0] < target)
			{
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		if (matrix[mid][0] > target)
		{
			mid = mid - 1;
		}
		if (mid < 0) return false;
		int t = mid;
		low = 0;
		high = n - 1;
		while (low <= high)
		{

			mid = (low + high) / 2;
			if (matrix[t][mid] == target)
			{
				return true;
			}
			if (matrix[t][mid] < target)
			{
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return false;

	}
};
