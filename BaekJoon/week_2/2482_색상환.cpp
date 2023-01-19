#include<iostream>
using namespace std;
int dp[1000][1000];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  int k; cin >> k;
  for(int i=2; i<=n; i++)
    dp[1][i] = i;
  
  for(int i=2; i<=k; i++)
    for(int j=3; j<=n; j++)
      dp[i][j] = (dp[i][j-1]+dp[i-1][j-2])%1000000003;
    
  cout << dp[k][n];
}