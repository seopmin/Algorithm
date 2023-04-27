#include<iostream>
#include<algorithm>
using namespace std;
int arr[3][1001], dp[3][1001];

int main() {
  int n; cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
    dp[0][i] = min(dp[1][i-1], dp[2][i-1])+arr[0][i];
    dp[1][i] = min(dp[0][i-1], dp[2][i-1])+arr[1][i];
    dp[2][i] = min(dp[1][i-1], dp[0][i-1])+arr[2][i];
  }
  
  cout << min(dp[0][n], min(dp[1][n], dp[2][n]));
}