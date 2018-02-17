#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
	/*
	* @param A: a string
	* @param B: a string
	* @return: a boolean
	*/
	void Qsort(string &a, int low, int high)
	{
		if (low >= high) {
			return;
		}
		int first = low;
		int end = high;
		int key = a[first];
		while (first < end) {
			while ((first<end)&&(a[end]>=key))
			{
				--end;
			}
			a[first] = a[end];
			while ((first<end) && (a[first] <= key))
			{
				++first;
			}
			a[end] = a[first];
		}
		a[first] = key;
		Qsort(a, first + 1, high);
		Qsort(a, low, first - 1);
	}

	bool Permutation(string &A, string &B) {
		// write your code here
		qsort(&A,A.length()-1,sizeof(A[0]),compare);

		return !strcmp(A.c_str(), B.c_str());
	}
};


int main() {

	return 0;
}


