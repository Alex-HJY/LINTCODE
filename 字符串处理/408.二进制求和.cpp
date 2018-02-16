class Solution {
public:
	/**
	* @param a: a number
	* @param b: a number
	* @return: the result
	*/
	string addBinary(string &a, string &b) {
		// write your code here
		string ans;
		int la = a.length();
		int lb = b.length();
		if (la < lb) {
			swap(a, b);
			swap(la, lb);
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int aa, bb, mo, di,t;
		t=aa = bb = mo = di = 0;
		for (int i = 0; i < la; i++) {
			aa = (int)a[i]-'0';
			if (i < lb) { bb = (int)b[i] - '0'; }else { bb = 0; }
			t = (aa + bb + di);
			mo = t % 2;
			di = t / 2;
			ans = ans + to_string(mo);
		}
		if (di) {
			ans = ans + to_string(di);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};