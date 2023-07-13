#include<iostream>
using namespace std;
int res, cnt=1;
char wheels[5][9];

// 톱니바퀴를 돌리는 함수
void spin(int w, int dir) {
  char temp;
  if(dir==1) {  // 오른쪽으로 spin
    temp=wheels[w][8];
    for(int i=8; i>1; i--) wheels[w][i]=wheels[w][i-1];
    wheels[w][1]=temp;
  } else {  // 왼쪽으로 spin
    temp=wheels[w][1];
    for(int i=1; i<8; i++) wheels[w][i] = wheels[w][i+1];
    wheels[w][8]=temp;
  }
}


// 오른쪽 재귀적으로 탐색하며 톱니바퀴를 돌리는 함수
void right_side(int w, int dir) {
  if(w>4) return;  // 기저조건: 오른쪽에 톱니바퀴가 없을 때
  if(wheels[w][3] != wheels[w+1][7]) {  // 오른쪽 톱니바퀴와 극이 다를 때
    right_side(w+1, -1*dir);  // 재귀 호출(방향전환: dir * -1)
    spin(w+1, -1*dir);
  }  
}

// 왼쪽을 재귀적으로 탐색하며 톱니바퀴를 돌리는 함수
void left_side(int w, int dir) {
  if(w<1) return;  // 기저조건: 왼족에 톱니바퀴가 없을 때
  if(wheels[w][7] != wheels[w-1][3]){  // 왼쪽 톱니바퀴와 극이 다를 때
    left_side(w-1, -1*dir);  // 재귀 호출(방향전환: dir * -1)
    spin(w-1, -1*dir);
  }
}


int main() {
  int k, w, dir;
  for(int i=1; i<=4; i++)
    for(int j=1; j<=8; j++)
      cin >> wheels[i][j];

  cin >> k;
  for(int i=0; i<k; i++) {
    cin >> w >> dir;
    right_side(w, dir);
    left_side(w, dir);
    spin(w, dir);
  }

  for(int i=1; i<=4; i++) {
    if(wheels[i][1]=='1') res += cnt;
    cnt *= 2;
  }
  cout << res;
}