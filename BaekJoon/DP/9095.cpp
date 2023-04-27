#include<iostream>
using namespace std;
int dp[11]={0,1,2,4,};

int main() {
  int n; cin >> n;

  for(int i=4; i<=11; i++)
    dp[i]=dp[i-3]+dp[i-2]+dp[i-1];

  for(int i=1; i<=n; i++) {
    int k; cin >> k;
    cout << dp[k] << '\n';
  }
}