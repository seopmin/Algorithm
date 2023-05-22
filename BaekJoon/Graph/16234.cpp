#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std;
int n, l, r, sum, map[51][51], visited[51][51], room_cnt;
vector<pair<int, int>> v;

// 알아야 할 것: 칸의 개수, 국경선 열린 칸의 총 합을 알아서 갱신되는 값 구함.
// 저장: 값을 갱신해야할 좌표들을 모음.
// 그 이후에 해야할 것 -> 값 세팅

void dfs(int x, int y, int prev_x, int prev_y, int discern) {
  if(x<0 || y<0 || x>=n || y>=n || visited[y][x]) return;
  // cout << "x: " << x << ", y: " << y << endl;
  int k=abs(map[y][x]-map[prev_y][prev_x]);
  if((k>=l && k<=r) || discern) { 
    visited[y][x]=1;
    sum+=map[y][x];
    room_cnt++;
    v.push_back({x, y});
    dfs(x+1, y, x, y, 0);
    dfs(x-1, y, x, y, 0);
    dfs(x, y+1, x, y, 0);
    dfs(x, y-1, x, y, 0);
  }
}

void setting(int val) {
  int x, y;
  for(int i=0; i<v.size(); i++) {
    tie(x, y) = v[i];
    // cout << "x: " << x << ", y: " << y << endl;
    map[y][x] = val;
  }
  // cout << "size: " << v.size() << endl;
}

int solve() {
  vector<pair<int, int>> temp;
  int dis=0;
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(!visited[i][j]) {
        sum=0; room_cnt=0;
        dfs(j, i, j, i, 1);
        if(room_cnt==1) dis++;
        else setting(sum/room_cnt);
        v = temp;
      }
    }
  }
  // cout << "current dis: " << dis << endl;
  if(dis==n*n) return 1;
  return 0;
}
int main() {
  cin >> n >> l >> r;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
    }
  }
  int cnt=0;
  int z=5;
  while(1) {
    if(solve()) { cout << cnt; break; }
    memset(visited, 0, sizeof(visited));
    // for(int i=0; i<n; i++) {
    //   for(int j=0; j<n; j++) {
    //     cout << map[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    cnt++;
  }

}