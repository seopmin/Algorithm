#include<iostream>
#include<string.h>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;
int w, h, sum;
int map[51][51];
int visited[51][51];
int dx[] = {0,0,1,-1, 1, 1, -1, -1};
int dy[] = {1,-1,0,0, 1, -1, -1, 1};

void init() {
  memset(visited, 0, sizeof(visited));
  sum=0;
}

int bfs(int x, int y) {
  if(visited[y][x]==1 || map[y][x]==0) return 0;
  queue<pair<int, int>> q;
  q.push({x, y});
  while(q.size()) {
    tie(x, y) = q.front(); q.pop();
    for(int i=0; i<8; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0 && ny>=0 && nx<w && ny<h) {
        if(visited[ny][nx]==1 || map[ny][nx]==0) continue;
        visited[ny][nx]=1;
        q.push({nx, ny});
      }
    }
    
  }
  return 1;
}

int main() {
  vector<int> v;
  while(1) {
    cin >> w >> h;
    if(w==0 && h==0) break;

    init();

    for(int i=0; i<h; i++)
      for(int j=0; j<w; j++)
        cin >> map[i][j];
    
    for(int i=0; i<h; i++)
      for(int j=0; j<w; j++)
        sum+=bfs(j, i);
    
    v.push_back(sum);
  }
  for(int i=0; i<v.size(); i++) {
    cout << v[i] << endl;
  }
}