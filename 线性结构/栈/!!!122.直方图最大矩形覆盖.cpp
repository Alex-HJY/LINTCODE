
class Solution {
public:
	/**
	* @param height: A list of integer
	* @return: The area of largest rectangle in the histogram
	*/
	int largestRectangleArea(vector<int> &height) {
		// write your code here
		stack<int> s;
		int l = height.size();
		height.push_back(0);
		int ans = 0;
		for (int i = 0; i <= l; i++)
		{
			while (!s.empty() && (height[i]<height[s.top()]))
			{
				int temp = i;
				if (s.size() != 1)
					temp = i - s.top();
				cout << s.size() << height[s.top()] << s.top() << endl;
				ans = max(ans, height[s.top()] * temp);
				s.pop();
			}
			s.push(i);
		}
		return ans;
	}
};
