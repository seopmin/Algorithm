// dfs 중 가장 깊은 노드를 찾는 문제인줄 알았지만 -> bfs문제
#include<iostream>
#include<string.h>
#include<algorithm>
#include<tuple>
#include<queue>
using namespace std;
int n, m, result, visited[51][51];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
string s[51];
void bfs(int y, int x) {
  memset(visited, 0, sizeof(visited));
  visited[y][x]=1;
  queue<pair<int, int>> q;
  q.push({y, x});
  while(q.size()) {
    tie(y, x) = q.front(); q.pop();
    for(int i=0; i<4; i++) {
      int ny = y+dy[i];
      int nx = x+dx[i];
      if(ny<0 || nx<0 || ny>=n || nx>=m || visited[ny][nx] || s[ny][nx]=='W') continue;
      visited[ny][nx] = visited[y][x]+1;
      q.push({ny,nx});
      result = max(result, visited[ny][nx]);
    }
  }
  return;
}

int main() {
  cin >> n >> m;
  for(int i=0; i<n; i++)
    cin >> s[i];

  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(s[i][j] == 'L') bfs(i,j);

  cout << result-1;
}




// int Y, X, result=0;
// string s[51];
// int visited[51][51]={0};

// void dfs(int y, int x, int depth) {
//   if(x<0 || y<0 || x>=X || y>=Y || s[y][x]==87 || visited[y][x]) {
//     // cout << "depth: " << depth << endl;
//     result = max(result, depth);
//     return;
//   }
//   visited[y][x]=1;
//   dfs(y+1, x, depth+1);
//   dfs(y-1, x, depth+1);
//   dfs(y, x-1, depth+1);
//   dfs(y, x+1, depth+1);
//   visited[y][x]=0;
// }

// int main() {
//   cin >> Y >> X;
//   for(int i=0; i<Y; i++)
//     cin >> s[i];
//   cout << (s[0][0] == 'W') << endl;

//   cout << 1 << endl;
//   for(int i=0; i<Y; i++){
//     for(int j=0; j<X; j++){
//       cout << s[i][j];  
//       dfs(i, j, 0);
//     }
//     cout << endl;
//   }
    

  
//   cout << result;
// }