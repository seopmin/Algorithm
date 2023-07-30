/* 14891 톱니바퀴 */

/*
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

*/







// 15683 감시
/*
#include<iostream>
#include<vector>
using namespace std;

int n, m, res = 99;
char map[9][9];
// 방향 정보를 저장하는 배열
// dir - 상: 0, 우: 1, 하: 2, 좌: 3
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
// CCTV 정보를 저장하는 구조체
typedef struct { int x; int y; int dir; char type; } CCTV;
vector<CCTV> v; // 모든 CCTV 정보를 저장하는 벡터

// 해당 방향으로 감시 가능한 영역을 설정하는 함수
void setting(int dir, int x, int y) {
    int nx = x + dx[dir], ny = y + dy[dir];
    while (nx >= 0 && ny >= 0 && nx < m && ny < n) {
        if (map[ny][nx] == '6') break; // 벽을 만나면 종료
        if (map[ny][nx] == '0')
            map[ny][nx] = '#'; // 빈 공간이면 감시 영역으로 설정
        nx += dx[dir];
        ny += dy[dir];
    }
}

// 모든 CCTV의 방향을 설정하는 함수
void explore() {
    int copy_map[9][9];
    // 맵 정보를 복사하여 사용 (다음 탐색을 위해 원래의 맵 정보를 유지하기 위함)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copy_map[i][j] = map[i][j];
        }
    }

    // 모든 CCTV에 대해 방향 설정 및 감시 영역 설정
    for (int i = 0; i < v.size(); i++) {
        int dir = v[i].dir;
        int x = v[i].x, y = v[i].y;
        char type = v[i].type;
        if (type == '1') { // CCTV 1의 경우
            setting((1 + dir) % 4, x, y);
        } else if (type == '2') { // CCTV 2의 경우
            setting((1 + dir) % 4, x, y);
            setting((3 + dir) % 4, x, y);
        } else if (type == '3') { // CCTV 3의 경우
            setting((0 + dir) % 4, x, y);
            setting((1 + dir) % 4, x, y);
        } else if (type == '4') { // CCTV 4의 경우
            setting((0 + dir) % 4, x, y);
            setting((1 + dir) % 4, x, y);
            setting((3 + dir) % 4, x, y);
        } else if (type == '5') { // CCTV 5의 경우
            setting((0 + dir) % 4, x, y);
            setting((1 + dir) % 4, x, y);
            setting((2 + dir) % 4, x, y);
            setting((3 + dir) % 4, x, y);
        }
    }

    // 감시되지 않은 빈 공간의 개수 카운트
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '0')
                cnt++;
            map[i][j] = copy_map[i][j]; // 복사해둔 맵 정보로 원래 상태로 복원
        }
    }
    res = min(res, cnt); // 최소 빈 공간 개수 업데이트
}

// CCTV의 방향을 설정하는 모든 경우의 수를 확인하는 함수
void func(int depth) {
    if (depth == v.size()) { // 모든 CCTV에 대해 방향을 설정했으면
        explore(); // 감시 영역을 설정하고 빈 공간 개수를 카운트
        return;
    }
    for (int i = 0; i < 4; i++) { // 각 CCTV에 대해 4가지 방향으로 설정
        v[depth].dir = (v[depth].dir + i) % 4;
        func(depth + 1); // 다음 CCTV로 넘어감
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    // 맵 정보와 CCTV 정보 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] != '0' && map[i][j] != '6') {
                // CCTV가 있는 경우, 해당 정보를 구조체에 저장하여 벡터에 추가
                CCTV c = {j, i, 0, map[i][j]};
                v.push_back(c);
            }
        }
    }

    func(0); // 모든 CCTV의 방향을 설정하는 모든 경우의 수를 확인

    cout << res; // 최소 빈 공간 개수 출력

    return 0;
}
*/

// 15684 사다리 조각
/*

#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, h, m, y, x, visited[31][11], result=INT_MAX;

bool check() {
  for(int i=1; i<=n; i++) {
    int pos=i;
    for(int j=1; j<=h; j++) {
      if(visited[j][pos]) pos++;
      else if(visited[j][pos-1]) pos--;
    }
    if(i!=pos) return false;
  }
  return true;
}

void func(int pos, int cnt) {
  if(cnt>3 || cnt>=result) return ;
  if(check()) {
    result = min(result, cnt);
    return;
  }
  for(int i=pos; i<=h; i++) {
    for(int j=1; j<=n; j++) {
      if(visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue;
      visited[i][j]=1;
      func(i, cnt+1);
      visited[i][j]=0;
    }
  }
}

int main() {
  cin >> n >> m >> h;
  for(int i=0; i<m; i++) {
    cin >> y >> x;
    visited[y][x]=1;
  }
  func(1, 0);
  if(result==INT_MAX) cout << -1;
  else cout << result;
}

*/


// 15685 드래곤 커브
/*
#include<iostream>
#include<vector>
using namespace std;
int map[101][101], cnt;
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

// setting 함수는 드래곤 커브를 그리는 함수로, 시작점과 방향, 세대 정보를 받아서 맵에 드래곤 커브를 그립니다.
// 맵은 100x100 크기의 2차원 배열로, 각 셀은 드래곤 커브에 속하는지 여부를 나타냅니다.
// 드래곤 커브를 그리는 알고리즘은 재귀적으로 동작합니다.
// 각 세대마다 이전 세대의 드래곤 커브를 시계 방향으로 90도 회전시켜 맨 뒤에 이어붙이는 방식으로 그립니다.
// 각 세대에 대한 드래곤 커브를 그릴 때, 맵 상에서 드래곤 커브에 해당하는 위치에 1을 표시합니다.
// 이렇게 그려진 드래곤 커브들을 이용하여 1x1 크기의 정사각형이 모두 드래곤 커브에 포함되는지 확인합니다.


// 0: 오른쪽 방향 (→)
// 1: 위쪽 방향 (↑)
// 2: 왼쪽 방향 (←)
// 3: 아래쪽 방향 (↓)

// cnt 변수는 모든 드래곤 커브에 포함되는 정사각형의 개수를 저장합니다.

// setting 함수에서는 드래곤 커브를 그릴 때 맵을 1로 설정하며, 이를 통해 드래곤 커브가 그려진 위치를 나타냅니다.
// setting 함수는 재귀적으로 동작하며, 현재 세대의 드래곤 커브에 대한 정보를 이전 세대와 연결하여 그립니다.

void setting(vector<int> v, int x, int y, int depth) {
  if(depth == 0) {
    int nx = x, ny = y;
    for(int i=0; i<v.size(); i++) {
      nx = nx + dx[v[i]];
      ny = ny + dy[v[i]];
      map[ny][nx] = 1;
    }
    return;
  } 

  vector<int> nv = v;
  for(int i = v.size() - 1; i >= 0; i--)
    nv.push_back((nv[i] + 1) % 4);
  
  setting(nv, x, y, depth - 1);
}

int main() {
  int n, x, y, d, g;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x >> y >> d >> g;
    map[y][x] = 1;
    vector<int> v;
    v.push_back(d);
    setting(v, x, y, g);
  }

  // 모든 드래곤 커브에 대해 맵 상에서 1x1 정사각형이 드래곤 커브에 포함되는지 확인합니다.
  // 맵에서 4개의 정사각형을 모두 포함하면 cnt를 1 증가시킵니다.
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      if(map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
        cnt++;
    }
  }

  cout << cnt;
}

*/