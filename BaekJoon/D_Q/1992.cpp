#include<iostream>
using namespace std;
char map[65][65];

bool check(int l_x, int r_x, int l_y, int r_y) {
  char com=map[l_y][l_x];
  for(int i=l_y; i<=r_y; i++) {
    for(int j=l_x; j<=r_x; j++) {
      if(com!=map[i][j]) return false;
    }
  }
  return true;
}

void solve(int l_x, int r_x, int l_y, int r_y) {
  if(check(l_x, r_x, l_y, r_y)) {
    cout << map[l_y][l_x];
    return;
  }
  if(l_x>=r_x || l_y>=r_y) return ;
  cout << '(';
  int mid_x = (l_x+r_x)/2;
  int mid_y = (l_y+r_y)/2;
  solve(l_x, mid_x, l_y, mid_y);
  solve(mid_x+1, r_x, l_y, mid_y);
  solve(l_x, mid_x, mid_y+1, r_y);
  solve(mid_x+1, r_x, mid_y+1, r_y);
  cout << ')';
}

int main() {
  int n; cin >> n;
  int l_x=0, r_x=n-1, l_y=0, r_y=n-1;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
    }
  }

  solve(l_x, r_x, l_y, r_y);
}