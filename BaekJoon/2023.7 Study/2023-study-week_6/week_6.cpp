/* 16236 아기 상어 */
/*
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
  vector<pair<int, int>> v;
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
      // print();
      // cout << "먹은 물고기 위치 " << x+1 << ' ' << y+1 <<endl;
      // cout << visited[y][x]-1 << ' ' << baby_shark_size << endl;
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
*/

/* 미세먼지 안녕 */
/*
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int r, c, t, a[51][51], spread[51][51], pos_t, pos_b;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void func2(int x, int y) {  // 확산되는 미세먼지를 구하는 함수
	int sp = a[y][x]/5, cnt=0;
	for(int i=0; i<4; i++) {
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || ny<0 || nx>=c || ny>=r || a[ny][nx]==-1) continue;
		cnt++;
		spread[ny][nx]+=sp;
	}
	a[y][x] -= cnt*sp;
}

void func() {  // 해당 위치에 미세먼지가 있는지 확인하는 함수
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(a[i][j]==-1 || a[i][j]==0) continue;
			func2(j, i);
		}
	}
}

void sum_f() {  // 확산된 미세먼지를 해당 맵에 더하는 함수
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(a[i][j]==-1) continue;
			a[i][j] += spread[i][j];
		}
	}
}

void clean_f() {  // 미세먼지를 청소하는 함수
	for(int i=pos_t; i>=0; i--)
		a[i][0]=a[i-1][0];
	
	for(int i=pos_b; i<r; i++)
		a[i][0]=a[i+1][0];

	for(int i=0; i<c; i++) {
		a[0][i] = a[0][i+1];
		a[r-1][i] = a[r-1][i+1];
	}

	for(int i=0; i<pos_t; i++)
		a[i][c-1]=a[i+1][c-1];

	for(int i=r-1; i>pos_b; i--) 
		a[i][c-1]=a[i-1][c-1];

	for(int i=c-1; i>1; i--) {
		a[pos_t][i]=a[pos_t][i-1];
		a[pos_b][i]=a[pos_b][i-1];
	}
	a[pos_t][1]=0;
	a[pos_b][1]=0;
}

int main() {
	cin >> r >> c >> t;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> a[i][j];
			if(a[i][j]==-1) pos_b=i;
		}
	}
	pos_t = pos_b-1;

	for(int i=0; i<t; i++) {
		func();
		sum_f();
		memset(spread, 0, sizeof(spread));
		clean_f();
		a[pos_b][0]=-1, a[pos_t][0]=-1;
	}

	long long result=0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(a[i][j]==-1) continue;
			result += a[i][j];
		}
	}

	cout << result;
}
*/