// 1. 치킨 거리가 가장 작은 M개의 치킨집을 골라 벡터에 거리 정보만 저장



#include<iostream>
#include<string.h>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;
int n, m, arr[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int result[14];

int bfs(int x, int y, int depth) {
  queue<tuple<int, int, int>> q;
  q.push({x, y, depth});
  while(!q.empty()) {
    tie(x, y, depth) = q.front(); q.pop();
    for(int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=1 && ny>=1 && nx<=5 && ny<=5) {
        if(arr[nx][ny]==1) return depth+1;
        q.push({nx, ny, depth+1});
      }
    }
  }
  return 0;
}

void push(int d) {
  result[0]=d;
  for(int i=1; i<=m; i++) {
    if(result[i-1] < result[i])
      swap(result[i-1], result[i]);
  }
}

void set() {
  for(int i=0; i<14; i++)
    result[i] = INT_MAX;
}

int main() {
  cin >> n >> m;
  set();
  
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin >> arr[i][j];
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(arr[i][j]!=2) continue;
      int distance = bfs(i, j, 0);
      cout << distance << endl;
      push(distance);
    }
  }
  int sum=0;
  for(int i=1; i<=m; i++){
    cout << result[i] << endl;
    sum += result[i];
  }

  cout << sum;

}