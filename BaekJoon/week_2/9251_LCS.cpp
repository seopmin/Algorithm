#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s1,s2; cin >> s1 >> s2;
  int dp[1001][1001];
  
  int l1=s1.size(), l2=s2.size();
  for(int i=1; i<=l1; i++) {
    for(int j=1; j<=l2; j++) {
      if(s1[i-1]==s2[j-1]) 
        dp[i][j] = ++dp[i-1][j-1];
      else 
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  cout << dp[l1][l2];
}