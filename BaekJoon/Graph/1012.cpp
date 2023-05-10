#include<iostream>
using namespace std;
int map[51][51], visited[51][51];
int t, m, n, k, x, y;

void dfs(int y, int x) {
  if(visited[y][x]) return;
  if(x<0 || y<0 || x>=m || y>=n || !map[y][x]) return;
  visited[y][x]=1;
  dfs(y+1, x);
  dfs(y-1, x);
  dfs(y, x+1);
  dfs(y, x-1);
}

void initial() {
  for(int i=0; i<51; i++) {
    for(int j=0; j<51; j++) {
      map[i][j]=0;
      visited[i][j]=0;
    }
  }
}

int main() {
  int t; cin >> t;
  while(t--) {
    cin >> m >> n >> k;
    while(k--) {
      cin >> x >> y;
      map[y][x]=1;
    }
    int cnt=0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        if(map[i][j] && !visited[i][j]) {
          dfs(i, j);
          cnt++;
        }
      }
    }
    cout << cnt << endl;
    initial();
  }
}