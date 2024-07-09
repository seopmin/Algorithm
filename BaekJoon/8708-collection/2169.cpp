#include <iostream>
#include <limits>
using namespace std;

int arr[1002][1002];
int dp1[1002][1002];
int dp2[1002][1002];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> arr[i][j];

    // 배열 초기화
    for (int i=0; i<=1001; i++) {
        for (int j=0; j<=1001; j++) {
            dp1[i][j] = numeric_limits<int>::min();
            dp2[i][j] = numeric_limits<int>::min();
        }
    }
    dp1[1][0] = 0;
    dp2[1][0] = 0;

    for (int j=1; j<=m; j++) {
        dp1[1][j] = dp1[1][j-1] + arr[1][j];
        dp2[1][j] = dp2[1][j-1] + arr[1][j];
    }

    for (int i=2; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + arr[i][j];
        }
        for (int j=m; j>0; j--) {
            dp2[i][j] = max(dp2[i-1][j], dp2[i][j+1]) + arr[i][j];
        }
        for (int j=1; j<=m; j++) {
            dp1[i][j] = max(dp1[i][j], dp2[i][j]);
            dp2[i][j] = dp1[i][j];
        }
    }
    cout << dp1[n][m];
}