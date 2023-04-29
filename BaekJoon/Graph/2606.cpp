#include<iostream>
#include<vector>
using namespace std;
vector<int> v[101];
int result=0, visited[101];

void bfs(int n) {
  if(visited[n]) return;
  visited[n]=1;
  result++;
  for(int i=0; i<v[n].size(); i++) {
    bfs(v[n][i]);
  }
}

int main() {
  int n, k; cin >> n >> k;
  for(int i=0; i<k; i++) {
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  bfs(1);
  cout << result-1;
}