
class Solution {
public:
	/*
	* @param points: an array of point
	* @return: An integer
	*/
	int maxPoints(vector<Point> &points) {
		// write your code here
		int l = points.size();
		int ans = 2;
		for (int i = 0; i < l; i++) {
			int x1 = points[i].x;
			int y1 = points[i].y;
			for (int j = 0; j < l; j++) {
				int t = 2;
				int x2 = points[j].x;
				int y2 = points[j].y;
				if (i == j) continue;
				for (int k = 0; k < l; k++) {
					if (k == i) continue;
					if (j == i) continue;
					int x3 = points[k].x;
					int y3 = points[k].y;
					if (x1 == x2) {
						if (x3 == x1) ++t;
					}
					else if ((x3!=x2)&&(x3!=x1))
					{
						double k1 = 1.0* (y1 - y2)/(x1 - x1) ;
						double k2 = 1.0* (y1 - y3) / (x1 - x3);
						if (k1 == k2) ++t;
					}
					

				}
				ans = max(ans, t);
			}
		}
		return ans;
	}
};

