#include<iostream>
using namespace std;
int n, map[101][101];
long long dp[101][101];

int main() {
  cin >> n;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      cin >> map[i][j];

  dp[1][1]=1;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(i==n && j==n) continue;
      if(i+map[i][j]<=n)
        dp[i+map[i][j]][j] += dp[i][j]; 
      if(j+map[i][j]<=n)
        dp[i][j+map[i][j]] += dp[i][j];
    }
  }
  cout << dp[n][n];
}