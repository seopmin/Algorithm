#include<iostream>
#include<vector>
using namespace std;
int arr[7];
int n, m;
void dfs(int h) {
  if(h==m) {
    for(int i=0; i<h; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  
  for(int i=1; i<=n; i++) {
    arr[h]=i;
    dfs(h+1);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  dfs(0);
}