#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int N, K, L, X, x, y, map[101][101], sec, current_dir=4;
char C;
pair<int, int> tail_pos = {0, 0}, head_pos = {0, 0};
queue<pair<int, char>> dir;

void print() {
  cout << endl;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cout << map[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  cin >> N;
  cin >> K;
  for(int i=0; i<K; i++) {
    cin >> y >> x;
    map[y-1][x-1]=5;  // 사과의 위치: 5
  }
  cin >> L;
  for(int i=0; i<L; i++) {
    cin >> X >> C;
    dir.push({X, C});
  }

  // 상: 1, 하: 2, 좌: 3, 우: 4
  map[0][0]=4;
  while(1) {
    int hx=head_pos.first;
    int hy=head_pos.second;
    current_dir = map[hy][hx];

    // 방향 바꾸기
    tie(X, C) = dir.front();
    if(sec == X) {
      if(C=='L') {
        if(current_dir==1) map[hy][hx]=3;
        else if(current_dir==2) map[hy][hx]=4;
        else if(current_dir==3) map[hy][hx]=2;
        else if(current_dir==4) map[hy][hx]=1;
      } else {
        if(current_dir==1) map[hy][hx]=4;
        else if(current_dir==2) map[hy][hx]=3;
        else if(current_dir==3) map[hy][hx]=1;
        else if(current_dir==4) map[hy][hx]=2;
      }
      current_dir=map[hy][hx];
      dir.pop();
    } 
    
    // 방향에 따른 head_pos의 이동
    if(current_dir==1) hy -= 1;
    else if(current_dir==2) hy += 1;
    else if(current_dir==3) hx -= 1;
    else hx += 1;
    head_pos = {hx, hy};

    // 이동했으니, 1초 추가
    sec++;

    // 벽에 부딪혔다면 -> 종료
    if(hx<0 || hy<0 || hx>=N || hy>=N) { cout << sec; return 0; }
    // 본인의 몸에 부딪혔다면 -> 종료
    if(map[hy][hx]<5 && map[hy][hx]>0) { cout << sec; return 0; }

    if(map[hy][hx]==5) {  // 사과를 먹었다면
      map[hy][hx]=current_dir;
    } else {  // 사과를 먹지 못했다면 꼬리도 이동해야함.
      map[hy][hx]=current_dir;
      int tx=tail_pos.first;
      int ty=tail_pos.second;
      int tail_dir=map[ty][tx];  // tail이 이동해야하는 방향
      map[ty][tx]=0;  // 꼬리는 이동해야하니, 전에 있던 꼬리 위치 0으로 초기화

      if(tail_dir==1) ty -= 1;
      else if(tail_dir==2) ty += 1;
      else if(tail_dir==3) tx -= 1;
      else tx += 1;

      tail_pos = {tx, ty}; 
    }
  }
}