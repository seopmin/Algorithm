/* 연구소 3 풀이 */
// 1. 바이러스가 모두 퍼질 수 있는 map의 크기 count(즉 벽 제외하고 모두 count)
//    -> 이를 possible_map 변수로 지정하겠음.
// 2. 활성화된 바이러스 m개를 뽑아 q에 넣음
// 3. bfs 알고리즘을 이용해 바이러스가 확산될 때마다 virus_cnt 증가
// 4. virus_cnt와 possible_map이 같을 때 최소값(res)을 업데이트 시킴
// 출력: 업데이트 된 최소값(res) 출력

#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, m, map[51][51], visited[51][51], x, y, res=INT_MAX;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
int active_virus[11];
int possible_map=0;

void bfs() {
  int virus_cnt=virus.size();  // 현재 있는 바이러스 수로 초기화

  if(virus_cnt==possible_map) {  // 이미 모든 바이러스가 퍼져있는 경우
    res=0;
    return ;
  }
  while(q.size()) {
    tie(x, y) = q.front(); q.pop();

    for(int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx<0 || ny<0 || nx>=n || ny>=n) continue;  // 범위 초과
      if(visited[ny][nx]) continue;  // 이미 방문
      if(map[ny][nx]==1) continue;  // 벽
      if(map[ny][nx]!=2) virus_cnt++;

      visited[ny][nx] = visited[y][x]+1;
      if(virus_cnt==possible_map) {  // 최소값 갱신
        res = min(res, visited[y][x]);
        return ;
      }
      q.push({nx, ny});
    }
  }

}

void func(int pos, int depth) {
  if(depth == m) {
    memset(visited, 0, sizeof(visited));
    while(q.size()) q.pop();
    for(int i=0; i<11; i++) {
      if(active_virus[i]) {
        q.push(virus[i]);
        visited[virus[i].second][virus[i].first] = 1;
      }
    }
    bfs();
    return ;
  }
  for(int i=pos+1; i<virus.size(); i++) {  // pos+1로 사용하면 방문 확인을 굳이 하지 않아도 됨
    active_virus[i]=1;
    func(i, depth+1);
    active_virus[i]=0;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
      if(map[i][j]==2) virus.push_back({j, i});
      if(map[i][j]!=1) possible_map++;  // 바이러스가 모두 퍼질 수 있는 최대 개수 count
    }
  }
  for(int i=0; i<virus.size(); i++) {
    active_virus[i]=1;
    func(i, 1);
    active_virus[i]=0;
  }
  if(res==INT_MAX) cout << -1;
  else cout << res;
}