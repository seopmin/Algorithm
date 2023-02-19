#include<iostream>
#include<string.h>
#include<algorithm>
#include<tuple>
#include<queue>
using namespace std;
string s[101];
int visited[101][101];
int n, m, result=0;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int x, int y, int depth) {
  queue<tuple<int, int, int>> q;
  q.push({x, y, depth});
  visited[y][x]=1;
  while(q.size()) {
    tie(x, y, depth) = q.front(); q.pop();
    if(x==m-1 && y==n-1)
      result=max(result, depth);
    
    for(int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0 && ny>=0 && nx<m && ny<n && !visited[ny][nx] && s[ny][nx]=='1') {
        visited[ny][nx] = visited[y][x]+1;
        q.push({nx, ny, depth+1});
      }
    }
  }

}

int main() {
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> s[i];
  bfs(0,0,1);
  cout << result;
}





// dfs 시간초과...

// #include<iostream>
// #include<limits.h>
// using namespace std;
// string s[101];
// int visited[101][101];
// int n, m, result=INT_MAX;

// void dfs(int x, int y, int depth) {
//   if(x<0 || y<0 || x>=m || y>=n) return;
//   if(s[y][x]=='0') return;
//   if(x==m-1 && y==n-1) {
//     result = min(result, depth);
//     return;
//   }
//   if(visited[y][x]) return;

//   visited[y][x]=1;
//   dfs(x+1, y, depth+1);
//   dfs(x-1, y, depth+1);
//   dfs(x, y+1, depth+1);
//   dfs(x, y-1, depth+1);
//   visited[y][x]=0;
// }

// int main() {
//   cin >> n >> m;
//   for(int i=0; i<n; i++) cin >> s[i];

//   dfs(0, 0, 1);
//   cout << result;
// }