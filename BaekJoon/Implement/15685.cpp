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

// 입력값 N은 드래곤 커브의 개수를 나타냅니다.
// 각 드래곤 커브는 시작점(x, y), 시작 방향 d(0~3), 세대 g(0~10)으로 주어집니다.
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
