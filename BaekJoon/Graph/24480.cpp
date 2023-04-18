#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int visited[100001];
int arr[100001];
int cnt=1;

bool comp(int a, int b) {
  return a > b;
}

void dfs(int node, vector<vector<int>> &v) {
  if(visited[node]) {
    return;
  }
  arr[node] = cnt++;
  visited[node]=1;
  for(int i=0; i<v[node].size(); i++) {
    dfs(v[node][i], v);
  }
}

int main() {
  int n, m, r; cin >> n >> m >> r;
  vector<vector<int>> v(n+1);
  for(int i=0; i<m; i++) {
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  for(int i=1; i<=n; i++)
    sort(v[i].begin(), v[i].end(), comp);

  dfs(r, v);

  for(int i=1; i<=n; i++)
    cout << arr[i] << '\n';

}