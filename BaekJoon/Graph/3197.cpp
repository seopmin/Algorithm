#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int x, y, r, c, visited[1501][1501], dis=0;
char map[1501][1501];
queue<pair<int, int>> q, nq, swan_q, swan_nq;
pair<int, int> swan_pos;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void swan_bfs() {
  while(swan_q.size() && !dis) {
    tie(y, x) = swan_q.front(); swan_q.pop();
    for(int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(nx >= 0 && ny>=0 && nx < c && ny < r && !visited[ny][nx]) {
        if(map[ny][nx] == '.') {
          visited[ny][nx] = 1;
          swan_q.push({ny, nx});
        } else if(map[ny][nx] == 'L') {
          visited[ny][nx] = 1;
          dis = 1;
          break;
        } else if (map[ny][nx] == 'X') {
          visited[ny][nx] = 1;
          swan_nq.push({ny, nx});
        }
      }
    }
  }
}

void water_bfs() {
  while(q.size()) {
    tie(y, x) = q.front(); q.pop();

    for(int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(nx>=0 && ny>=0 && nx<c && ny<r) {
        if(map[ny][nx] == 'X') {
          map[ny][nx] = '.';
          nq.push({ny, nx});
        }
      }
    }
  }
}

int main() {
  cin >> r >> c;
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      cin >> map[i][j];
      if(map[i][j] != 'X') q.push({i, j});
      if(map[i][j] == 'L') {
        swan_pos.first = i;
        swan_pos.second = j;
      }
    }
  }
  
  int day=0;
  swan_q.push({swan_pos.first, swan_pos.second});
  visited[swan_pos.first][swan_pos.second] = 1;
  while(!dis) {
    swan_bfs();
    if(!dis) {
      water_bfs();
      q = nq;
      swan_q=swan_nq;
      while(nq.size()) nq.pop();
      while(swan_nq.size()) swan_nq.pop();
      day++;
    }
  }
  cout << day;
  
}