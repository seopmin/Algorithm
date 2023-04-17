#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> dp{0, 1, 2};

  for(int i=3; i<=n; i++) 
    dp.push_back((dp[i-1]+dp[i-2])%10007);
  cout << dp[n];
}