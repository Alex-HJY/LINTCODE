class Solution {
public:
	/**
	* @param num: An integer
	* @return: true if num is an ugly number or false
	*/
	vector<int> a;

	bool sushu(int num) {
		int max = (int)sqrt(num*1.0);
		for (int i = 2; i <= max; i++) {
			if (num %i == 0) {
				return false;
			}
		}
		return true;
	}

	bool isUgly(int num) {
		// write your code here
		if (num == 1) return 1;
		if (num <= 0) return 0;
		int max = (int)sqrt(num*1.0);
		for (int i = 2; i <= max; i++) {
			if (num %i == 0) {
				a.push_back(i);
				a.push_back(num / i);
			}
		}
		for (int i = 0; i < a.size(); i++) {
			int t = a[i];
			if ((t == 2) || (t == 3) || (t == 5)) continue;
			if (sushu(t)) return false;
		}
		return 1;
	}
};
