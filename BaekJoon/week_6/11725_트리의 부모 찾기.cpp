#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, a, b, parent_node[100001]={0}, visited[100001]={0};
vector<int> node[100001];

void bfs(int d) {
  queue<int> q;
  q.push(d);
  visited[d]=1;
  while(!q.empty()) {
    int x = q.front(); q.pop();
    for(int i=0; i<node[x].size(); i++) {
      int y=node[x][i];
      if(!visited[y]){
        q.push(y);
        visited[y]=1;
        parent_node[y]=x;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i=1; i<n; i++) {
    cin >> a >> b;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  bfs(1);
  for(int i=2; i<=n; i++)
    cout << parent_node[i] << '\n';
}