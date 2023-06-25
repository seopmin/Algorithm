#include<iostream>
#include<algorithm>
using namespace std;
int n, max_e, last;

void check(int a[][21]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max_e = max(max_e, a[i][j]);
		}
	}
}

// 최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록
void func(int depth, int map[21][21], int dir) {
	if (depth == 5) {
		check(map);

		return;
	}
	int a[21][21];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			a[i][j] = map[i][j];
		}
	}

	// 위쪽으로 이동
	if (dir == 1) {
		for (int i = 0; i < n; i++) {
			last = 0;
			for (int j = 1; j < n; j++) {
				int k = j;
				while (k != last) {
					if (a[k][i] == 0) break;
					if (a[k - 1][i] == 0) {
						a[k - 1][i] = a[k][i];
						a[k][i] = 0;
					}
					else if (a[k][i] == a[k - 1][i]) {
						a[k - 1][i] *= 2;
						a[k][i] = 0;
						last = k;
						break;
					}
					else if (a[k][i] != a[k - 1][i]) {
						break;
					}
					k--;
				}
				/*
				cout << endl;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						cout << a[i][j] << ' ';
					}
					cout << endl;
				}
				cout << "las: " << last << endl;
				*/
			}
		}
		
	}
	// 아래로 이동
	if (dir == 2) {
		for (int i = 0; i < n; i++) {
			last = n - 1;
			for (int j = n - 2; j >= 0; j--) {
				int k = j;
				while (k != last) {
					if (a[k][i] == 0) break;
					if (a[k + 1][i] == 0) {
						a[k + 1][i] = a[k][i];
						a[k][i] = 0;
					}
					else if (a[k][i] == a[k + 1][i]) {
						a[k + 1][i] *= 2;
						a[k][i] = 0;
						last = k;
						break;
					}
					else if (a[k][i] != a[k + 1][i]) {
						break;
					}
					k++;
				}
			}
		}
	}
	// 오른쪽으로 이동
	if (dir == 3) {
		for (int i = 0; i < n; i++) {
			last = n - 1;
			for (int j = n - 2; j >= 0; j--) {
				int k = j;
				while (k != last) {
					if (a[i][k] == 0) break;
					if (a[i][k + 1] == 0) {
						a[i][k + 1] = a[i][k];
						a[i][k] = 0;
					}
					else if (a[i][k] == a[i][k + 1]) {
						a[i][k + 1] *= 2;
						a[i][k] = 0;
						last = k;
						break;
					}
					else if (a[i][k] != a[i][k + 1]) {
						break;
					}
					k++;
				}
			}
		}
	}
	// 왼쪽으로 이동
	if (dir == 4) {
		for (int i = 0; i < n; i++) {
			last = 0;
			for (int j = 1; j < n; j++) {
				int k = j;
				while (k != last) {
					if (a[i][k] == 0) break;
					if (a[i][k - 1] == 0) {
						a[i][k - 1] = a[i][k];
						a[i][k] = 0;
					}
					else if (a[i][k] == a[i][k - 1]) {
						a[i][k - 1] *= 2;
						a[i][k] = 0;
						last = k;
						break;
					}
					else if (a[i][k] != a[i][k - 1]) {
						break;
					}
					k--;
				}
			}
		}
	}
	func(depth + 1, a, 1);
	func(depth + 1, a, 2);
	func(depth + 1, a, 3);
	func(depth + 1, a, 4);
}


int main() {
	int  a[21][21];
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	func(0, a, 1);
	func(0, a, 2);
	func(0, a, 3);
	func(0, a, 4);
	cout << max_e;
}