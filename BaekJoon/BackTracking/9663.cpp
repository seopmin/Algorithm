#include<iostream>
using namespace std;
int N, a[16][16], nx, ny, cnt;

// 퀸을 놓을 수 있는지 확인하는 함수
// 놓을 수 있으면 1, 없으면 0 반환
bool check(int y, int x) {
  nx=x, ny=y;
  while(nx-- && ny--)
    if(a[ny][nx]) return 0;

  nx=x, ny=y;
  while(nx++<N && ny--)
    if(a[ny][nx]) return 0;

  nx=x, ny=y;
  while(ny--)
    if(a[ny][nx]) return 0;

  return 1;
}

// 퀸을 놓는 함수
void setting(int depth) {
  if(depth == N) { cnt++; return; }
  for(int i=0; i<N; i++) {
    if(check(depth, i)) {
      a[depth][i]=1;
      setting(depth+1);
      a[depth][i]=0;
    }
  }
}

int main() {
  cin >> N;
  setting(0);
  cout << cnt;
}