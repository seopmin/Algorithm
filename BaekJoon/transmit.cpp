#include<iostream>
using namespace std;
int n, m, h, visited[11][31], a, b;


int check() {
  for(int i=1; i<=h; i++) {
    int pos=i;
    for(int j=0; j<n; j++) {
      if(visited[i][j]) pos++;
    }
  }
}

void func(int pos, int cnt) {
  if(cnt>3) return;
  if(check()) {

  }
}

int main() {
  cin >> n >> m >> h;
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    visited[a][b]=1;
  }
  func(1, 0);
}