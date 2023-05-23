#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int r, c, j_x, j_y, j_d, f_x, f_y, f_d, jh_visited[1002][1002], fire_visited[1002][1002];
char map[1002][1002];
queue<tuple<int ,int, int>> jh;
queue<tuple<int, int, int>> fire;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

// 지훈이 이동 -> 불 이동
// 지훈이 이동하려 q에서 위치 꺼낼 때 그 위치가 fire자리이면 이동 X

int jh_func() {
  for(int i=0; i<4; i++) {
    int x = j_x+dx[i];
    int y = j_y+dy[i];
    if(map[y][x]=='F') continue;
    if(x==0 || y==0 || x==c+1 || y==r+1) {
      cout<<j_d+1; 
      return 1;
    }
    if(x>0 && y>0 && x<=c && y<=r && !jh_visited[y][x] && map[y][x] != '#' && map[y][x] == '.') {
      jh_visited[y][x] = 1;
      jh.push({x, y, j_d+1});
    }
  }
  return 0;
}

void fire_func() {
  for(int i=0; i<4; i++) {
    int x = f_x+dx[i];
    int y = f_y+dy[i];
    if(x>0 && y>0 && x<=c && y<=r && !fire_visited[y][x] && map[y][x] != '#') {
      map[y][x]='F';
      fire_visited[y][x] = 1;
      fire.push({x, y, f_d+1});
    }
  }
}

void bfs() {
  int dis=0;
  while(jh.size()) {
    
    tie(j_x, j_y, j_d) = jh.front();
    tie(f_x, f_y, f_d) = fire.front();
    if(j_d>f_d && fire.size()) { 
      fire.pop();
      map[f_y][f_x]='F';
      fire_func(); 
    } else { 
      jh.pop(); 
      if(map[j_y][j_x]!='F') { map[j_y][j_x]='J'; dis=jh_func();}
      if(dis) return;
    }
  }
  cout << "IMPOSSIBLE";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> r >> c;
  for(int i=1; i<=r; i++) {
    for(int j=1; j<=c; j++) {
      cin >> map[i][j];
      if(map[i][j]=='J') { jh.push({j,i,0}); jh_visited[i][j]=1; }
      else if(map[i][j]=='F') { fire.push({j,i,0}); fire_visited[i][j]=1; }
    }
  }
  
  bfs();
}