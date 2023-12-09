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

