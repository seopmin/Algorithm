#include<iostream>
using namespace std;
int n, m;
int visited[9];

void func(int k, int depth) {
  if(depth==m) return;
  cout << k << ' ';
  for(int i=1; i<=n; i++) {
    if(visited[i]) continue;
    visited[i]=1;
    func(i, depth+1);
    visited[i]=0;
  }
}

int main() {
  cin >> n >> m;

  for(int i=1; i<=n; i++) {
    visited[i]=1;
    func(i, 0);
    visited[i]=0;
    cout << '\n';
  }

}