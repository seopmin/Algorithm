#include<iostream>
#include<algorithm>
using namespace std;
int n, m, map[501][501], res, visited[501][501];

void side_dfs(int x1, int y1, int x2, int y2, int sum) {
	if(x1<0 || x1>=m || y1<0 || y1>=n) return ;
	if(x2<0 || x2>=m || y2<0 || y2>=n) return ;
	if(visited[y1][x1] || visited[y2][x2]) return;

	sum += (map[y1][x1]+map[y2][x2]);
	res = max(sum, res);
}

void dfs(int depth, int sum, int x, int y) {
	if(x<0 || x>=m || y<0 || y>=n) return ;
	if(visited[y][x]) return;
	sum += map[y][x];
	if(depth == 3) {

		res = max(res, sum);
		return;
	}
	visited[y][x]=1;

	if(depth==1) {
		side_dfs(x-1, y, x+1, y, sum);
		side_dfs(x, y+1, x, y-1, sum);
	}
	
	dfs(depth+1, sum, x+1, y);
	dfs(depth+1, sum, x-1, y);
	dfs(depth+1, sum, x, y+1);
	dfs(depth+1, sum, x, y-1);
	visited[y][x]=0;
}

int main() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			dfs(0, 0, j, i);
		}
	}
	cout << res;
}