#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n, k, arr[101], dp[100001];

int main() {
  cin >> n >> k;
  for(int i=1; i<=n; i++) {
    cin >> arr[i];
  }
  memset(dp, 10001, 100001*sizeof(int));
  dp[0]=0;
  for(int i=1; i<=k; i++) {
    for(int j=1; j<=n; j++) {
      if(i-arr[j]>=0) {
        dp[i]=min(dp[i],dp[i-arr[j]]+1);
      }
    }
  }
  if(dp[k] >= 10001) {
    cout << -1;
    return 0;
  }
  cout << dp[k];
}