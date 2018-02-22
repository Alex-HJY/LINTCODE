class Solution {
public:
	/**
	* @param s1: A string
	* @param s2: A string
	* @param s3: A string
	* @return: Determine whether s3 is formed by interleaving of s1 and s2
	*/
	bool isInterleave(string &s1, string &s2, string &s3) {
		// write your code here
		int **d = new int*[s3.length() + 1];
		for (int i = 0; i <= s3.length(); i++) {
			d[i] = new int[s3.length() + 1];
		}
		for (int i = 0; i <= s3.length(); i++) {
			for (int j = 0; j <= s3.length(); j++) {
				d[i][j] = 0;
			}
		}
		d[0][0] = true;
		int l1 = s1.length();
		int l2 = s2.length();
		int l3 = s3.length();
		if (!l1) return  !strcmp(s2.c_str(), s3.c_str());
		if (!l2) return !strcmp(s1.c_str(), s3.c_str());
		if (!l3) return false;
		if (l2 + l1 != l3) return false;
		s1 = " " + s1;
		s2 = " " + s2;
		s3 = " " + s3;
		if (s3[1] == s1[1])
			d[1][1] = true;
		if (s3[1] == s2[1])
			d[1][0] = true;

		for (int i = 2; i <= l3; i++) {
			for (int j = 1; j <= min(l1,i); j++) {
				if (s3[i] == s1[j]) {
					d[i][j] = (d[i - 1][j - 1]||d[i][j]);
				}
			}
			for (int j = 1; j <= min(l2, i); j++) {
				if (s3[i] == s2[j]) {
					d[i][i-j] =( d[i - 1][i-j]||d[i][i-j]);
				}
			}

		}
		return d[l3][l1];
	}
};
