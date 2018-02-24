
class Solution {
public:
	/*
	* @param matrix: matrix, a list of lists of integers
	* @param target: An integer
	* @return: a boolean, indicate whether matrix contains target
	*/
	int searchMatrix(vector<vector<int>> &matrix, int target) {
		// write your code here
		const int m = matrix.size();
		if (!m) return  false;
		const int n = matrix[0].size();
		auto high = m - 1;
		auto low = 0;
		int ans = 0;
		int mid = 0;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (matrix[mid][0] == target)
			{
				ans += 1;
				break;
			}
			if (matrix[mid][0] < target)
			{
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		if (matrix[mid][0] < target)
		{
			mid = mid + 1;
		}
		int midd = mid;
		cout << midd << endl;
		for (int t = 0; t<midd; t++)
		{
			low = 0;
			high = n - 1;
			while (low <= high)
			{

				mid = (low + high) / 2;
				if (matrix[t][mid] == target)
				{
					ans += 1;
					break;
				}
				if (matrix[t][mid] < target)
				{
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}
			}
		}
		return ans;

	}
};