#include<iostream>
#include<algorithm>
using namespace std;
int n, m, map[501][501], res, visited[501][501];

// 인접한 두 셀 (x1, y1)과 (x2, y2)의 값을 더해서 합산하는 함수
void side_dfs(int x1, int y1, int x2, int y2, int sum) {
	if(x1<0 || x1>=m || y1<0 || y1>=n) return ;
	if(x2<0 || x2>=m || y2<0 || y2>=n) return ;
	if(visited[y1][x1] || visited[y2][x2]) return;

	sum += (map[y1][x1]+map[y2][x2]);
	res = max(sum, res);
}

// DFS를 이용하여 테트로미노를 놓을 수 있는 모든 경우를 탐색하는 함수
void dfs(int depth, int sum, int x, int y) {
	if(x<0 || x>=m || y<0 || y>=n) return ;
	if(visited[y][x]) return;
	sum += map[y][x];
	if(depth == 4) {
		res = max(res, sum);
		return;
	}
	visited[y][x]=1;

	if(depth==2) {
		// 현재 셀의 인접한 옆 위치를 확인하기 위해 side_dfs 함수 호출
		side_dfs(x-1, y, x+1, y, sum);
		side_dfs(x, y+1, x, y-1, sum);
	}
	
	// 상하좌우 4방향으로 재귀적으로 탐색
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

	// 각 셀에서 DFS 함수 호출하여 최대 합 계산
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			dfs(1, 0, j, i);
		}
	}
	cout << res;
}