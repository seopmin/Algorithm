#include<iostream>
#include<tuple>
#include<queue>
using namespace std;

int n, m, dis, ro, bo, depth, dir;
char map[11][11];
int dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};

void func(int rx, int ry, int bx, int by) {
  queue<tuple<int, int, int, int, int>> q;
  q.push({0, rx, ry, bx, by}); // 시작 상태를 큐에 넣음

  while(q.size()) {
    tie(depth, rx, ry, bx, by) = q.front(); q.pop(); // 큐에서 상태를 꺼냄
    if(depth==10) break ; // 최대 10번까지만 움직임

    for(int i=0; i<4; i++) {
      int nrx=rx, nry=ry, nbx=bx, nby=by, rd=0, bd=0;
      while(map[nry+dy[i]][nrx+dx[i]]!='#' && map[nry][nrx]!='O') { // 빨간 구슬 이동
        nry += dy[i];
        nrx += dx[i];
        rd++;
      }
      while(map[nby+dy[i]][nbx+dx[i]]!='#' && map[nby][nbx]!='O') { // 파란 구슬 이동
        nby += dy[i];
        nbx += dx[i];
        bd++;
      }
      
      if(map[nby][nbx]=='O') continue; // 파란 구슬이 구멍에 도착한 경우는 무시
      if(map[nry][nrx]=='O') { // 빨간 구슬이 구멍에 도착한 경우
        cout << depth+1; // 현재 움직인 횟수에 1을 더한 값을 출력
        return;
      }
      if(nrx==nbx && nry==nby) { // 빨간 구슬과 파란 구슬이 같은 위치에 도착한 경우
        if(rd > bd) { // 이동 거리를 비교하여 더 많이 이동한 구슬을 한 칸 뒤로 이동
          nrx -= dx[i];
          nry -= dy[i];
        } 
        else {
          nbx -= dx[i];
          nby -= dy[i];
        }
      }

      q.push({depth+1, nrx, nry, nbx, nby}); // 새로운 상태를 큐에 넣음
    }
  }
  cout << -1; // 함수가 종료되지 않고 큐가 비었을 때는 빨간 구슬을 구멍을 통해 빼낼 수 없음
}

int main() {
  int rx, ry, bx, by;
  cin >> n >> m;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> map[i][j];
      if(map[i][j]=='R') { rx=j, ry=i; } // 빨간 구슬의 위치 저장
      if(map[i][j]=='B') { bx=j, by=i; } // 파란 구슬의 위치 저장
    }
  }

  func(rx, ry, bx, by); // 함수 호출하여 결과 출력
  return 0;
}
