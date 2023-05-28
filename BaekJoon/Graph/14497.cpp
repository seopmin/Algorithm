#include<iostream>
#include<queue>
#include<tuple>
#include<string.h>
using namespace std;
int n, m, x, y, x_jun, y_jun, x_bum, y_bum, result_cnt=0;
char map[301][301];
int visited[301][301];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

// 주난이의 점프 파동이 움직이는 bfs
void bfs() {
  // cout << "bfs start" << endl;
  queue<pair<int, int>> q;
  q.push({x_jun, y_jun});
  visited[y_jun][x_jun]=1;
  while(q.size()) {
    tie(x, y) = q.front(); q.pop();
    for(int i=0; i<4; i++) {
      int n_x = x+dx[i];
      int n_y = y+dy[i];
      if(n_x>0 && n_y>0 && n_x<=m && n_y<=n && !visited[n_y][n_x]) {
        if(map[n_y][n_x]!='0') map[n_y][n_x]='0';
        else q.push({n_x, n_y});
        visited[n_y][n_x] = 1;
      }
    }
  }
  // cout << "bfs exit" << endl;
}


// 범인이 주난이와 바로 연결되어 있는지 확인하는 bfs
int find_bfs() {
  // cout << "find_bfs start" << endl;
  queue<pair<int, int>> q;
  q.push({x_bum, y_bum});
  visited[y_bum][x_bum]=1;
  while(q.size()) {
    tie(x, y) = q.front(); q.pop();
    // cout << "x: " << x << ", y: " << y << endl;
    if(x==x_jun && y==y_jun) { cout << result_cnt; return 1; }
    for(int i=0; i<4; i++) {
      int n_x = x+dx[i];
      int n_y = y+dy[i];
      if(n_x>0 && n_y>0 && n_x<=m && n_y<=n && !visited[n_y][n_x] && map[n_y][n_x]!='1') {
        visited[n_y][n_x]=1;
        q.push({n_x, n_y});
      }
    }
  }
  return 0;
}

int main() {
  cin >> n >> m;
  cin >> y_jun >> x_jun >> y_bum >> x_bum;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      cin >> map[i][j];
  
  while(1) {
    bfs();
    result_cnt++;
    memset(visited, 0, sizeof(visited));
    if(map[y_bum][x_bum]=='0') break;
  }
  cout << result_cnt;
}