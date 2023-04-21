#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int n, m, v;
vector<int> vec[1001];
int visited[1001];

void dfs(int k) {
  if(visited[k]) return;
  visited[k]=1;
  cout << k << ' ';
  for(int i=0; i<vec[k].size(); i++)
    dfs(vec[k][i]);

}

void bfs() {
  queue<int> q;
  q.push(v);
  while(q.size()) {
    int k = q.front(); q.pop();
    if(visited[k]) continue;
    visited[k]=1;
    cout << k << ' ';
    for(int i=0; i<vec[k].size(); i++) {
      q.push(vec[k][i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> v;
  for(int i=0; i<m; i++) {
    int a, b; cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  for(int i=1; i<=n; i++)
    sort(vec[i].begin(), vec[i].end());

  dfs(v);
  memset(visited, 0, 1001 * sizeof(int));
  cout << '\n';
  bfs();
}