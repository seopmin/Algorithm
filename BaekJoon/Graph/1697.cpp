#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int visited[200002];
int bfs(int n, int k) {
  queue<pair<int, int>> q;
  q.push({n, 0});

  while(q.size()) {
    int n, depth; tie(n,depth)=q.front(); q.pop();
    visited[n]=1;
    if(n==k) {
      return depth;
    }
    if(n+1 < 100001 && !visited[n+1]) {
      q.push({n+1, depth+1});
    }
    if(n*2 < 200002 && !visited[n*2]) {
      q.push({n*2, depth+1});
    } 
    if(n-1 >= 0 && !visited[n-1]) {
      q.push({n-1, depth+1});
    }
  }
  return -1;
}

int main() {
  int n, k; cin >> n >> k;
  
  cout << bfs(n, k);
}