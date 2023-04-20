#include<iostream>
#include<limits.h>
using namespace std;
int n, m, map[1001][1001], dp[1001][1001];

int main() {
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cin >> map[i][j];
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      int result = max(dp[i][j-1], max(dp[i-1][j], dp[i-1][j-1]));
      dp[i][j] = result + map[i][j];
    }
  }

  cout << dp[n][m];
}