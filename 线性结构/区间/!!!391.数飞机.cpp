class Solution {
public:
	/*
	* @param airplanes: An interval array
	* @return: Count of airplanes are in the sky.
	*/
	int countOfAirplanes(vector<Interval> &airplanes) {
		// write your code here
		int ans = 0, t = 0;
		map<int, int> set;
		int l = airplanes.size();
		for (int i = 0; i < l; ++i)
		{
			if (set.find(airplanes[i].start) != set.end())
				set[airplanes[i].start] += 1;
			else
			{
				set[airplanes[i].start] = 1;
			}
			if (set.find(airplanes[i].end) != set.end())
				set[airplanes[i].end] -= 1;
			else
			{
				set[airplanes[i].end] = -1;
			}
		}

		for (map<int, int>::iterator it = set.begin(); it != set.end(); it++)
		{
			t += it->second;
			ans = max(ans, t);
		}
		return  ans;
	}

};
