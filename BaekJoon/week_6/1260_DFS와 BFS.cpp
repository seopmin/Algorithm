#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int n, m, v, a, b;
vector<int> vec[1002];
int visited[1002]={0};

void dfs(int node) {
  cout << node << ' ';
  visited[node]=1;

  for(int i=0; i<vec[node].size(); i++) {
    if(!visited[vec[node][i]])
      dfs(vec[node][i]);
  }
}

void bfs(int d) {
  queue<int> q;
  q.push(d);
  visited[d]=1;
  while(!q.empty()) {
    int x = q.front(); q.pop();
    cout << x << ' ';

    for(int i=0; i<vec[x].size(); i++) {
      int y=vec[x][i];
      if(!visited[y]){
        q.push(y);
        visited[y]=1;
      }
    }
  }
}

int main() {
  cin >> n >> m >> v;
  for(int i=1; i<=m; i++) {
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  for(int i=1; i<=n; i++) {
    sort(vec[i].begin(), vec[i].end());
  }
  dfs(v);
  cout<<endl;
  memset(visited,0,sizeof(visited));
  bfs(v);
}