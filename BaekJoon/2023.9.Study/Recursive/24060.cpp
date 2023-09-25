#include<iostream>
#include<vector>
using namespace std;
int n, k, res=-1;
int A[500001];

void merge(int A[], int p, int q, int r) {
	int i = p, j = q + 1;
	vector<int> temp;
	while(i<=q && j<=r) {
		if (A[i] <= A[j]) {
			temp.push_back(A[i++]);
		}
		else {
			temp.push_back(A[j++]);
		}
	}
	while (i <= q) temp.push_back(A[i++]);
	while (j <= r) temp.push_back(A[j++]);
	i = p; 
	int t = 0;
	while (i <= r) {
		k--;
		A[i++] = temp[t++];
		if (k==0) {
			res = temp[t - 1];
		}
	}
}

void merge_sort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	merge_sort(A, 0, n - 1);
	cout << res;
}