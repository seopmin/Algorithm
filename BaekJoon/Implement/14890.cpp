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

    // 유효한 경로의 개수를 계산
    for(int i=0; i<n; i++) {
        cnt += check_1(i);
    }
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<n; i++) {
        cnt += check_2(i);
    }
    
    cout << cnt;
}

