class Solution {
public:
	/*
	* @param A: an array
	* @return: total of reverse pairs
	*/
	long ans = 0;
	void mergesort(int low, int mid, int high, vector<int> &num) {
		int *temp = new int[high - low + 1];
		int i = low;// ��ָ��
		int j = mid + 1;// ��ָ��
		int k = 0;
		while (i <= mid && j <= high) {
			if (num[i] <= num[j]) {
				temp[k++] = num[i++];

			}
			else {
				temp[k++] = num[j++];
				ans += (mid - i + 1);
			}
		}
		// �����ʣ�������������
		while (i <= mid) {
			temp[k++] = num[i++];
		}

		// ���ұ߱�ʣ�������������
		while (j <= high) {
			temp[k++] = num[j++];
		}

		// ���������е�������nums����
		for (int k2 = 0; k2 < high - low + 1; k2++) {
			num[k2 + low] = temp[k2];
		}
	}
	void ssort(int low, int high, vector<int> &a) {
		int mid = (low + high) / 2;
		if (low < high) {
			ssort(low, mid, a);
			ssort(mid + 1, high, a);
			mergesort(low, mid, high, a);
		}
	}
	long long reversePairs(vector<int> &A) {
		// write your code here
		ssort(0, A.size() - 1, A);
		return ans;
		
	}
};