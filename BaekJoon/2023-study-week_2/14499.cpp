#include<iostream>
using namespace std;
int n, m, x, y, k, map[21][21], dice[6], temp;
int dx[5]={0,1,-1,0,0}, dy[5]={0,0,0,-1,1};  // 동:1 , 서:2, 북:3, 남: 4

// 현재 위치, 움직이는 방향
int move(int dir) {
  temp=dice[1];
  if(dir==1) {
    dice[1]=dice[4];
    dice[4]=dice[0];
    dice[0]=dice[5];
    dice[5]=temp;
  }
  else if(dir==2) {
    dice[1]=dice[5];
    dice[5]=dice[0];
    dice[0]=dice[4];
    dice[4]=temp;
  }
  else if(dir==3) {
    dice[1]=dice[2];
    dice[2]=dice[0];
    dice[0]=dice[3];
    dice[3]=temp;
  }
  else if(dir==4) {
    dice[1]=dice[3];
    dice[3]=dice[0];
    dice[0]=dice[2];
    dice[2]=temp;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  // 입력 받을 때 주사위를 놓은 곳의 좌표 x, y를 주의하여 입력 받아야 함.
  cin >> n >> m >> y >> x >> k;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> map[i][j];

  dice[1]=map[y][x];

  for(int i=0; i<k; i++){
    cin >> temp;
    int nx=x+dx[temp], ny=y+dy[temp];
    if(nx>=0 && nx<m && ny>=0 && ny<n) {
      x=nx, y=ny;
      move(temp);
      if(map[y][x]==0) map[y][x]=dice[1];
      else { dice[1]=map[y][x]; map[y][x]=0; }
      

      cout << dice[0] << '\n';
    }
  }
}