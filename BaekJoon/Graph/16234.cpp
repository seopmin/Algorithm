// 알아야 할 것: 
// 1. 칸의 개수
// 2. 국경선 열린 칸의 총 합
// 3. 연합의 위치 배열(저장)
// 4. 인구가 다시 갱신될 값 구함.
// 그 이후에 해야할 것 -> 값 세팅(인구이동)

#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std;
int n, l, r, sum, map[51][51], visited[51][51], room_cnt;
vector<pair<int, int>> v;

// DFS 함수: 인구 이동이 가능한 칸들을 탐색
void dfs(int x, int y, int prev_x, int prev_y, int discern) {
  if(x<0 || y<0 || x>=n || y>=n || visited[y][x]) return;
  int k=abs(map[y][x]-map[prev_y][prev_x]);
  if((k>=l && k<=r) || discern) {   // discern: dfs의 깊이 첫번째만 통과시키려고
    visited[y][x]=1;
    sum+=map[y][x]; // 연합의 총 인구수
    room_cnt++;
    v.push_back({x, y});
    dfs(x+1, y, x, y, 0);
    dfs(x-1, y, x, y, 0);
    dfs(x, y+1, x, y, 0);
    dfs(x, y-1, x, y, 0);
  }
}

// 설정 함수: 연합된 칸들의 인구를 재설정
void setting(int val) {
  int x, y;
  for(int i=0; i<v.size(); i++) {
    tie(x, y) = v[i];
    map[y][x] = val;
  }
}

// 인구 이동 가능한지 검사하고, 가능하다면 인구 이동 실행
int solve() {
  int dis=0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(!visited[i][j]) {
        sum=0; room_cnt=0;
        dfs(j, i, j, i, 1);
        if(room_cnt==1) dis++;
        else setting(sum/room_cnt);  // 연합된 칸들의 인구 재설정
        v.clear();
      }
    }
  }
  if(dis==n*n) return 1;  // 더이상 인구 이동이 없는 경우
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
  while(1) {
    if(solve()) { cout << cnt; break; }
    memset(visited, 0, sizeof(visited));
    cnt++;
  }
}
