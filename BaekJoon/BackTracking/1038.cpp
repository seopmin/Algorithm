#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<long long> v;

void bfs() {
  queue<long long> q;
  for(int i=0; i<10; i++) {
    q.push(i);
    v.push_back(i);
  }

  while(q.size()) {
    long long x = q.front(); q.pop();
    int comp = x%10;
    for(int i=0; i<10; i++) {
      if(i<comp) {
        long long temp = x*10+i;
        q.push(temp);
        v.push_back(temp);
      }
    }
  }
}

int main() {
  int n; cin >> n;
  bfs();
  
  if(v.size() <= n) cout << -1;
  else cout << v[n];
}