#include<iostream>
#include<vector>
using namespace std;
int a[9][9], nx, ny, done;
vector<pair<int ,int>> v;

bool check(int x, int y, int v) {
  for(int i=0; i<9; i++) {
    if(a[y][i]==v && i!=x) return 0;
    if(a[i][x]==v && i!=y) return 0;
  }
  nx=int(x/3)*3, ny=int(y/3)*3;
  for(int i=ny; i<ny+3; i++) {
    for(int j=nx; j<nx+3; j++) {
      if(a[i][j]==v && i!=y && j!=x) return 0;
    }
  }
  return 1;
}

void func(int n) {
  if(n==v.size()) { done=1; return; }

  int x=v[n].first, y=v[n].second;
  for(int i=1; i<=9; i++) {
    a[y][x]=i;
    if(check(x, y, i)) func(n+1);
    if(done) return;
  }
  a[y][x]=0;  // 백트래킹에서 원소를 다시 확인 할 때 값이 0이어야 하기 때문
}

int main() {
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      cin >> a[i][j];
      if(a[i][j]==0) v.push_back({j, i});
    }
  }

  func(0);

  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
      cout << a[i][j] << ' ';
    cout << '\n';
}