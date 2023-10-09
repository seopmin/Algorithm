#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, r;
vector<int> graph[100001];
int result[100001] = {0,};
int visited[100001] = {0,};
int cnt=0;

void bfs(int r){
  queue<int> q;
  q.push(r);
  result[r] = ++cnt;
  visited[r] = 1;

  while(!q.empty()){
    int temp = q.front();
    q.pop();
    for(int i=0; i<graph[temp].size(); i++){
      int k=graph[temp][i];
      if(!visited[k]){
        result[k] = ++cnt;
        q.push(k);
        visited[k]=1;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> r;
  for(int i=1; i<=m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for(int i=1; i<=n; i++)
    sort(graph[i].begin(), graph[i].end());

  bfs(r);

  for(int i=1; i<=n; i++){
    cout << result[i] << '\n';
  }
}