#include<iostream>
#include<vector>
using namespace std;
int n, m, cnt=0;
vector<int> v[1001];
int visited[1001];

void dfs(int k) {
  if(visited[k]) return;
  visited[k]=1;
  for(int i=0; i<v[k].size(); i++) {
    dfs(v[k][i]);
  }
}

int main() {
  cin >> n >> m;
  for(int i=0; i< m; i++) {
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=1; i<=n; i++) {
    if(!visited[i]) {
      cnt++;
      dfs(i);
    }
  }
  cout << cnt;
}