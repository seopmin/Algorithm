#include<iostream>
#include<algorithm>
using namespace std;
char map[51][51];
int n, result=0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void check(int y, int x) {
  char comp=map[y][x];
  int sum=1;
  int a=0, b=0, c=0, d=0;
  while(1) {
    if(comp==map[y+a+1][x] && y+a+1<n) {
      a++;
    } else if(comp==map[y-b-1][x] && y-b-1>=0) {
      b++;
    } else if(comp==map[y][x+c+1] && x+c+1<n) {
      c++;
    } else if(comp==map[y][x-d-1] && x-d-1>=0) {
      d++;
    } else {
      break;
    }
  }
  result=max(result, max(a+b,c+d)+1);
  // cout << "result: " << result << endl;
  // cout << "a: " << a << ",b: " << b << ",c: " << c << ",d: " << d << endl;
}

void func(int y, int x) {
  // cout << "i: " << y << ",j: " << x << endl;
  for(int i=0; i<4; i++) {
    int nx=dx[i]+x;
    int ny=dy[i]+y;
    if(nx>=0&&ny>=0&&nx<n&&ny<n) {
      swap(map[y][x], map[ny][nx]);
      check(y, x);
      swap(map[y][x], map[ny][nx]);
    }
  }
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      func(i, j);
    }
  }
  cout << result;
}