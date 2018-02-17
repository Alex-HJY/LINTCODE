class Solution {
public:
	/*
	* @param A: a string
	* @param B: a string
	* @return: a boolean
	*/
	void Qsort(string &a, int low, int high)
	{
		if (low >= high)
		{
			return;
		}
		int first = low;
		int last = high;
		int key = a[first];/*���ֱ�ĵ�һ����¼��Ϊ����*/
		while (first < last)
		{
			while (first < last && a[last] >= key)
			{
				--last;
			}
			a[first] = a[last];/*���ȵ�һ��С���Ƶ��Ͷ�*/
			while (first < last && a[first] <= key)
			{
				++first;
			}
			a[last] = a[first];
			/*���ȵ�һ������Ƶ��߶�*/
		}
		a[first] = key;/*�����¼��λ*/
		Qsort(a, low, first - 1);
		Qsort(a, first + 1, high);
	}
	bool Permutation(string &A, string &B) {
		// write your code here
		Qsort(A, 0, A.length() - 1);
		Qsort(B, 0, B.length() - 1);
		return !strcmp(A.c_str(), B.c_str());
	}
};