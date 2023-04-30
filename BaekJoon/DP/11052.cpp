#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001], dp[1001];

int main() {
  int n; cin >> n;
  for(int i=1; i<=n; i++)
    cin >> arr[i];

  for(int i=1; i<=n; i++) {
    dp[i]=arr[i];
    for(int j=i-1; j>=i/2; j--) {
      dp[i] = max(dp[i], dp[j]+arr[i-j]); 
    }
  }

  cout << dp[n];
}