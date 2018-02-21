
class Solution {
public:
	/**
	* @param numbers: An array of Integer
	* @param target: target = numbers[index1] + numbers[index2]
	* @return: [index1 + 1, index2 + 1] (index1 < index2)
	*/
	static bool cmp(int a, int b) {
		return a < b;
	}
	int search(int left, int right, int target, vector<int> &numbers) {
		while (left <= right) {
			int mid = (left + right) / 2;
			int t = numbers[mid];
			if (t == target)
				return mid;
			if (t > target) {
				right = mid - 1;
			}
			if (t < target) {
				left = mid + 1;
			}
		}

		return -1;
	}

	vector<int> twoSum(vector<int> &numbers, int target) {
		// write your code here
		int l = numbers.size();
		vector<int> ans;
		vector<int> temp=numbers;
		sort(numbers.begin(), numbers.end(), cmp);
		int t, tt;
		for (int i = 0; i <= l; i++) {
			 t = search(i + 1, l - 1, target - numbers[i], numbers);
			if (t != -1) {
				tt = i;
				break;
			}
		}
		for (int j = 0; j < l; j++) {
			if (temp[j] == numbers[t]) ans.push_back(j);
			else if (temp[j] == numbers[tt]) ans.push_back(j);
			if (ans.size()==2)return ans;
		}
				return ans;
	}
};