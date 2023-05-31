#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, m, h, visited[31][11], a, b, result=INT_MAX;

int check() {
  for(int i=1; i<=n; i++) {
    int pos=i;
    for(int j=1; j<=h; j++) {
      if(visited[j][pos]) pos++;
      else if(visited[j][pos-1]) pos--;
    }
    if(i != pos) return 0;
  }
  return 1;
}

void func(int pos, int cnt) {
  if(cnt>3 || cnt >= result) return;
  if(check()) {
    result = min(cnt, result);
    return;
  }
  for(int i=pos; i<=h; i++) {
    for(int j=1; j<=n; j++) {
      if(visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue;
      visited[i][j]=1;
      func(i, cnt+1);
      visited[i][j]=0;
    }
  }
}

int main() {
  cin >> n >> m >> h;
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    visited[a][b]=1;
  }
  func(1, 0);
  if(result==INT_MAX) cout << -1;
  else cout << result;
}