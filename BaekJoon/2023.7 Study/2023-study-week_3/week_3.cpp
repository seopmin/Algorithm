// 14503 로봇 청소기
/*
#include<iostream>
using namespace std;
int n, m , r, c, d, map[51][51], cnt, dis, nx, ny, nd;
// 북: 0, 동: 1, 남:2, 서: 3
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool check(int x, int y) {
	for(int i=0; i<4; i++) {
		nx=x+dx[i], ny=y+dy[i];
		if(nx>=0 && nx<m && ny>=0 && ny<n && !map[ny][nx]) return 0;
	}
	return 1;
}

void func(int x, int y, int d) {
	if(!map[y][x]) { // 1. 현재 칸이 청소되지 않은 칸이면 청소 표시
		cnt++;
		map[y][x]=2;  // 청소 표시: 2
	}

	if(check(x, y)) { // 2. 주변의 4칸 중 청소되지 않은 빈칸이 없는 경우
		nd = (d+2)%4;
		nx=x+dx[nd];
		ny=y+dy[nd];
		if(map[ny][nx] == 1) return ;
		func(nx, ny, d);  // 바라보는 방향 유지하면서 후진
	} else {  // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 있는 경우
		nd=d;
		for(int i=1; i<=4; i++) {
			nd = (nd+3)%4;  // 시계 반대방향 90도 회전
			nx=x+dx[nd];
			ny=y+dy[nd];
			if(!map[ny][nx]) {
				func(nx, ny, nd);
				break;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> map[i][j];
	func(c, r, d);
	cout << cnt;
}

*/

// 14888 연산자 끼워넣기
/*
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int N, A[101], op[4], res_min=INT_MAX, res_max=INT_MIN;

void func(int plus, int minus, int multi, int div, int depth, int sum) {
  if(depth == N-1) {
    res_min = min(res_min, sum);
    res_max = max(res_max, sum);
    return;
  }

  if(plus>0) func(plus-1, minus, multi, div, depth+1, sum+A[depth+1]);
	if(minus>0) func(plus, minus-1, multi, div, depth+1, sum-A[depth+1]);
	if(multi>0) func(plus, minus, multi-1, div, depth+1, sum*A[depth+1]);
	if(div>0) func(plus, minus, multi, div-1, depth+1, sum/A[depth+1]);
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> A[i];
  for(int i=0; i<4; i++)
    cin >> op[i];
  
  func(op[0], op[1], op[2], op[3], 0, A[0]);
  cout << res_max << '\n' << res_min;
}
*/

// 14889 스타트와 링크
/*
#include<iostream>
#include<algorithm>
#include<cmath>
#include<limits.h>
#include<vector>
using namespace std;
int n, map[21][21], a[21], res=INT_MAX;

// 함수 func2: start 팀과 link 팀의 능력치 차이 계산
void func2() {
  vector<int> v1; // start 팀의 번호를 저장하는 벡터
  vector<int> v2; // link 팀의 번호를 저장하는 벡터

  // a 배열에 따라 번호를 start 팀과 link 팀에 나누어 저장
  for(int i=0; i<n; i++) {
    if(a[i]) v1.push_back(i);
    else v2.push_back(i);
  }

  int v1_sum=0, v2_sum=0;
  // start 팀과 link 팀의 능력치 계산
  for(int i=0; i<v1.size(); i++) {
    for(int j=0; j<v1.size(); j++) {
      v1_sum += map[v1[i]][v1[j]];
      v2_sum += map[v2[i]][v2[j]];
    }
  }
  // 능력치 차이의 최소값 갱신
  res = min(res, abs(v1_sum-v2_sum));
}

// 함수 func: start 팀 구성하는 모든 경우의 수 확인
void func(int depth, int pos) {
  if(depth == n/2) {
    func2(); // start 팀 구성이 완료되면 능력치 차이 계산
    return;
  }
  for(int i=pos; i<n; i++) {
    if(a[i]) continue; // 이미 start 팀에 속한 경우 건너뛰기
    a[i]=1; // start 팀에 포함시킴
    func(depth+1, i); 
    a[i]=0; 
  }
}

int main() {
  cin >> n; // 인원 수 입력
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> map[i][j]; // 능력치 정보 입력

  func(0, 0); // start 팀 구성하는 모든 경우의 수 확인
  
  cout << res; // 최소 능력치 차이 출력

  return 0;
}
*/

// 14890 경사로
/*
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

int n, l, map[101][101], cnt, visited[101][101];

// 세로 방향(열)의 경로의 유효성을 확인하는 함수
int check_1(int x) {
  for(int i=0; i<n-1; i++) {
    int k = map[i][x] - map[i+1][x];
    // 높이 차이가 1이상이면 0 반환
    if(k != 1 && k != 0 && k != -1) return 0;

    // 경사를 아래로 향하게 놓는 경우
    if(k == 1) {
      i++;
      visited[i][x] = 1;
      for(int j=1; j<l; j++) {
        if(map[i][x] != map[i+1][x]) return 0;
        i++;
        if(i >= n) return 0;
        // 다리 놓은 곳에 방문 표시
        visited[i][x] = 1;
      }
      i--;
    }
  }

  // 반대편에서 다시 경사가 아래로 향하게 다리 놓기 시작
  for(int i=n-1; i>0; i--) {
    int k = map[i][x] - map[i-1][x];
    // 높이 차이가 1이상이면 0 반환
    if(k != 1 && k != 0 && k != -1) return 0;

    // 경사를 아래로 향하게 놓는 경우
    if(k == 1) {
      i--;
      // 이미 방문했으면 0 반환
      if(visited[i][x]) return 0;
      for(int j=1; j<l; j++) {
        if(map[i][x] != map[i-1][x]) return 0;
        i--;
        if(visited[i][x]) return 0;
        if(i < 0) return 0;
      }
      i++;
    }
  }
  return 1;
}

// 가로 방향(행)의 경로의 유효성을 확인하는 함수
int check_2(int y) {
  for(int i=0; i<n-1; i++) {
    int k = map[y][i] - map[y][i+1];
    // 높이 차이가 1이상이면 0 반환
    if(k != 1 && k != 0 && k != -1) return 0;
    // 경사를 아래로 향하게 놓는 경우
    if(k == 1) {
      i++;
      visited[y][i] = 1;
      for(int j=1; j<l; j++) {
        if(map[y][i] != map[y][i+1]) return 0;
        i++;
        if(i >= n) return 0;
        visited[y][i] = 1;
      }
      i--;
    }
  }

  // 반대편에서 다시 경사가 아래로 향하게 다리 놓기 시작
  for(int i=n-1; i>0; i--) {
    int k = map[y][i] - map[y][i-1];
    // 높이 차이가 1이상이면 0 반환
    if(k != 1 && k != 0 && k != -1) return 0;
    // 경사를 아래로 향하게 놓는 경우
    if(k == 1) {
      i--;
      if(visited[y][i]) return 0;
      for(int j=1; j<l; j++) {
        if(map[y][i] != map[y][i-1]) return 0;
        i--;
        if(visited[y][i]) return 0;
        if(i < 0) return 0;
      }
      i++;
    }
  }
  return 1;
}

int main() {
  cin >> n >> l;

  // 지도의 높이를 입력받음
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
    }
  }

  // 세로 방향 유효한 경로의 개수를 계산
  for(int i=0; i<n; i++) {
    cnt += check_1(i);
  }
  memset(visited, 0, sizeof(visited));

  for(int i=0; i<n; i++) {
    cnt += check_2(i);
  }
  
  cout << cnt;
}
*/