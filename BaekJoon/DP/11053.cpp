#include<iostream>
#include<algorithm>
using namespace std;
int map[1001], dp[1001];
int main() {
  int n; cin >> n;
  for(int i=1; i<=n; i++)
    cin >> map[i];
  
  for(int i=1; i<=n; i++) {
    dp[i]=1;
    for(int j=i-1; j>0; j--) {
      if(dp[i]>j) break;
      if(map[i]>map[j]) {
        dp[i]=max(dp[i], dp[j]+1);
      }
    }
  }
  
  int m=0;
  for(int i=1; i<=n; i++) {
    m = max(m, dp[i]);
  }
  cout << m;
}