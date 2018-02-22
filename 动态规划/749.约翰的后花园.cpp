class Solution {
public:
	/**
	* @param x: the wall's height
	* @return: YES or NO
	*/
	string isBuild(int x) {
		// write you code here
		bool d[1001];
		d[3] = 1;
		d[6] = 1;
		d[7] = 1;
		for (int i = 7; i <= x; i++) {
			d[i] = (d[i - 3] || d[i - 7]);
		}
		if (d[x])
			return "YES";
		return "NO";

	}
};