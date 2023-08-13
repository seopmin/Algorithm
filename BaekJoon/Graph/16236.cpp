/* 조건 */
// 본인보다 큰 물고기: 먹을 수 (X), 지나갈 수 (X)
// 본인과 똑같은 크기의 물고기: 먹을 수 (X), 지나갈 수 (O)
// 본인보다 작은 물고기: 먹을 수 (O), 지나갈 수 (O)

/* 아기 상어 이동 방식 */
// 1. 더 이상 먹을 수 있는 물고기가 없다면 어무니 상어에게 도움 요청
// 2. 먹을 수 있는 물고기가 한 마리면 -> 해당 물고기 먹으러 감
// 3. 먹을 수 있는 물고기가 두 마리 이상이면 -> 거리가 가장 가까운 물고기를 먹으러 감
// 3-1. 거리가 가까운 물고기가 많다면, 가장 위 - 가장 왼쪽 물고기를 먹는다.

/* 추가 정보 */
// 이동 속도: 1초
// 물고기 먹는 시간: 0초
// 본인의 크기와 같은 수의 물고기를 먹을 때 마다 1 증가

/* 출력 */
// 아기 상어가 어무니 상어에게 도움을 요청하지 않을 때까지의 시간 출력 

#include<iostream>
#include<tuple>
#include<queue>
#include<string.h>
using namespace std;
int n, map[21][21], visited[21][21];
int dx[]={0,-1,1,0}, dy[]={-1,0,0,1};  // 상->좌->우->하  방식으로 탐색(아기 상어 이동 방식에 맞춤)
pair<int, int> baby_shark; // x, y, 먹은 물고기 수
int baby_shark_size=2, cnt, dis, ny, nx;


void print() {
  cout << endl;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << map[i][j];
    }
    cout << endl;
  }
}

int bfs(int x, int y) {
	queue<tuple<int, int, int>> q;
	q.push({x, y, 0});
	visited[y][x]=1;
	while(q.size()) {
		tie(x, y, dis)=q.front(); q.pop();
    if(dis) {
      int distance = visited[y][x];
      while(q.size()) {
        tie(nx, ny, dis) = q.front(); q.pop();
        if(distance != visited[ny][nx]) break;
        if(!map[ny][nx]) continue;
        if(map[ny][nx] == baby_shark_size) continue; 
        if(y>ny || (y==ny && nx<x)) {
          x = nx;
          y = ny;
        }
      }
      baby_shark.first = x;
      baby_shark.second = y;
      cnt += visited[y][x]-1;
      map[y][x]=0;  // 먹은 자리 0으로 대체
      return 1;
    }

		for(int i=0; i<4; i++) {
			nx = x+dx[i];
			ny = y+dy[i];

			if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
			if(visited[ny][nx]) continue;
			if(map[ny][nx] > baby_shark_size) continue;  // 크기가 더 큰 물고기는 못 지나감
      visited[ny][nx]=visited[y][x]+1;  // 방문 표시와 함께 이동 시간 측정

			if(map[ny][nx] && map[ny][nx]<baby_shark_size) {  // 아기 상어보다 더 작은 물고기
        q.push({nx, ny, 1});
      } else {
        q.push({nx, ny, 0});
      }
		}
	}
  return 0;
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
      if(map[i][j]==9) {
        baby_shark={j, i};
        map[i][j]=0;
      }
    }
	}

  int amount=0;
	while(1) {
    memset(visited, 0, sizeof(visited));
		if(!bfs(baby_shark.first, baby_shark.second)) {
      cout << cnt;
      break;
    }
    amount++;
    if(baby_shark_size==amount) {
      amount = 0;
      baby_shark_size++;
    }
	}
}