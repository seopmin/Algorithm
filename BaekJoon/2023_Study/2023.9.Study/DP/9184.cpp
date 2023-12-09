#include<iostream>
#include<cstring>
using namespace std;
int visited[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) {
		visited[20][20][20] = w(20, 20, 20); 
		return visited[20][20][20];
	}
	if (visited[a][b][c]) return visited[a][b][c];
	if (a < b && b < c) {
		visited[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	visited[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return visited[a][b][c];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		int a, b, c;  cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		int res=w(a, b, c);
		printf("w(%d, %d, %d) = %d\n", a, b, c, res);
		memset(visited, 0, sizeof(visited));
	}
}