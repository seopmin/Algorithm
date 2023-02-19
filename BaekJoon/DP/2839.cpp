#include<iostream>
#include<algorithm>
using namespace std;
int n, dp[5001]={0,0,1,0,1,2,0};

int main() {
  cin >> n;

  for(int i=7; i<n; i++) {
    if(dp[i-3]==0) dp[i] = dp[i-5]+1;
    else if(dp[i-5]==0) dp[i] = dp[i-3]+1;
    else dp[i] = min(dp[i-3], dp[i-5])+1;
  }

  if(dp[n-1]==0) cout << -1;
  else cout << dp[n-1];
}