#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<string.h>
using namespace std;
int map[11][11];
int n, result = INT_MAX;
vector<pair<int, int>> v;
int visited[11][11];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int check() {
  int sum=0;
  for(int i=0; i<v.size(); i++) {
    int x=v[i].first, y=v[i].second;
    if(visited[y][x]) return -1;
    sum += map[y][x];
    visited[y][x]=1;
    for(int i=0; i<4; i++) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx<0 || ny<0 || nx>=n || ny>=n || visited[ny][nx]) return -1;
      visited[ny][nx]=1;
      sum += map[ny][nx];
    }
  }
  return sum;
}

void func(int y, int x, int cnt) {
  if(cnt==3) {
    int dis = check();
    if(dis!=-1) result = min(result, dis);
    for(int i=0; i<10; i++) {
      memset(visited[i], 0, sizeof(int)*10);
    }
    return ;
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      v.push_back({j, i});
      func(i, j, cnt+1);
      v.pop_back();
    }
  }
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      v.push_back({j, i});
      func(i, j, 1);
      v.pop_back();
    }
  }
  cout << result;
}