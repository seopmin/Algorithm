#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int main() {
  vector<int> dp{0,0};

  int n; cin >> n;
  int i=1;
  while(n-i >= 1) {
    i++;
    // cout << i << endl;
    int temp=INT_MAX;
    if(i%3==0)
      temp = min(temp, dp[i/3]+1);
    if(i%2==0)
      temp = min(temp, dp[i/2]+1);
    temp = min(temp, dp[i-1]+1);
    dp.push_back(temp);
  }
  // cout << dp[n-1];
  for(int i=0; i<=n; i++) {
    cout << dp[i] << endl;
  }
}