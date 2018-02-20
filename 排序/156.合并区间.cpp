class Solution {
public:
	/*
	* @param intervals: interval list.
	* @return: A new interval list.
	*/
	static bool cmp(Interval a, Interval b) {
		return a.start < b.start;
	}

	vector<Interval> merge(vector<Interval> &intervals) {
		// write your code here
		vector<Interval> ans;
		int l = intervals.size();
		if (l <= 0) return ans;
		sort(intervals.begin(), intervals.end(), cmp);
		Interval temp = intervals[0];
		for (int i = 1; i < l; i++) {
			if (intervals[i].start <= temp.end) {
				temp.end = max(temp.end, intervals[i].end);
			}
			else
			{
				ans.push_back(temp);
				temp = intervals[i];
			}
		}
			ans.push_back(temp);
				return ans;
	}

};
