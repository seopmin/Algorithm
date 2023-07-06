#include<iostream>
using namespace std;
int n, m, x, y, k, temp; 
int map[21][21];
int dice[6];
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
}

int main() {
  cin >> n >> m >> x >> y >> k;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> map[i][j];

  dice[1]=map[y][x];

  for(int i=0; i<k; i++){
    // cout << "input: ";
    cin >> temp;
    int nx=x+dx[temp], ny=y+dy[temp];
    // cout << "nx: " << nx << ", ny: " << ny << endl;
    if(nx>=0 && nx<m && ny>=0 && ny<n) {
      x=nx, y=ny;
      move(temp);
      if(map[y][x]==0) map[y][x]=dice[1];
      else { dice[1]=map[y][x]; map[y][x]=0; }
      // cout << 0 << dice[2] << 0 << endl;
      // cout << dice[5] << dice[1] << dice[4] << endl;
      // cout << 0 << dice[3] << 0 << endl;
      // cout << 0 << dice[0] << 0 << endl;
      // cout << endl; 
      cout << dice[0] << '\n';
    }
  }
}

/* 메모리 초과 */
// #include<iostream>
// using namespace std;
// int n, m, x, y, k, map[21][21];
// int dx[]={0,1,-1,0,0}, dy[]={0,0,0,-1,1};  // 동:1 , 서:2, 북:3, 남: 4
// int dice[4][3] = {
//   {0,0,0},
//   {0,0,0},
//   {0,0,0},
//   {0,0,0}
// };

// // 현재 위치, 움직이는 방향
// int move(int dir) {
//   int temp;
//   if(dir==1) {
//     temp=dice[3][1];
//     dice[3][1]=dice[1][2];
//     dice[1][2]=dice[1][1];
//     dice[1][1]=dice[1][0];
//     dice[1][0]=temp;
//   }
//   if(dir==2) {
//     temp=dice[3][1];
//     dice[3][1]=dice[1][0];
//     dice[1][0]=dice[1][1];
//     dice[1][1]=dice[1][2];
//     dice[1][3]=temp;
//   }
//   if(dir==3) {
//     temp=dice[3][1];
//     dice[3][1]=dice[2][1];
//     dice[2][1]=dice[1][1];
//     dice[1][1]=dice[0][1];
//     dice[0][1]=temp;
//   }
//   if(dir==4) {
//     temp=dice[0][1];
//     dice[0][1]=dice[1][1];
//     dice[1][1]=dice[2][1];
//     dice[2][1]=dice[3][1];
//     dice[3][1]=temp;
//   }

// }

// int main() {
//   cin >> n >> m >> x >> y >> k;
//   for(int i=0; i<n; i++)
//     for(int j=0; j<m; j++)
//       cin >> map[i][j];

//   dice[1][1]=map[y][x];
//   for(int i=0; i<k; i++){
//     // cout << "input: ";
//     int dir; cin >> dir;
//     int nx=x+dx[dir], ny=y+dy[dir];
//     // cout << "nx: " << nx << ", ny: " << ny << endl;
//     if(nx>=0 && nx<m && ny>=0 && ny<n) {
//       x=nx, y=ny;
//       move(dir);
//       dice[1][1]=map[y][x];
//       // for(int i=0; i<4; i++) {
//       //   for(int j=0; j<3; j++) {
//       //     cout << dice[i][j];
//       //   }
//       //   cout << endl;
//       // }
//       cout << dice[3][1] << '\n';
//     }

//   }

// }