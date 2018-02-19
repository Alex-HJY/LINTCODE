


class Solution {
public:
	/**
	* @param x: An integer
	* @return: The sqrt of x
	*/
	int sqrt(int x) {
		// write your code here
		if (x <= 0) return 0;
		if (x == 1) return 1;
		int low = 0, high = x / 2, mid = 0, ans;
		while ((low <= high)) {
			mid = (low + high) / 2;
			long long t = (long long)mid*mid;
			long long t1 = (long long)(mid + 1)*(mid + 1);
			cout << t << "  " << t1 << "  " << mid << endl;
			if (x == t) return mid;
			if ((t < x) && (t1 > x)) {
				return mid;
			}
			if (t > x) high = mid - 1;
			if (t1 < x) low = mid + 1;

		}
	}
};
