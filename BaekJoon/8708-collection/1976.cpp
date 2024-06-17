#include <iostream>
using namespace std;

int n, m;
int map[201][201];
int visited[201];

void func(int idx) {
    for (int i=1; i<=n; i++) {
        if (map[i][idx] && !visited[i]) {  // 길 방문 안한 곳이면
            visited[i]=1;
            func(i);
        }
    }
}

bool check() {
    int input; cin >> input;
    func(input);
    visited[input]=1;
    for (int i=0; i<m-1; i++) {
        cin >> input;
        if (!visited[input])
            return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> map[i][j];

    if (check())
        printf("YES");
    else
        printf("NO");
    
}