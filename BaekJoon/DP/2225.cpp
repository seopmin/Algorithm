#include<iostream>
#include<algorithm>
using namespace std;
long long dp[201][201];

int main() {
  int n, k; cin >> n >> k;
  for(int i=0; i<=max(n, k); i++) {
    dp[i][1] = 1;
    dp[0][i] = 1;
  }
  for(int i=1; i<=n; i++)
    for(int j=2; j<=k; j++)
      dp[i][j] = (dp[i-1][j]+dp[i][j-1])%1000000000;

  cout << dp[n][k];
}