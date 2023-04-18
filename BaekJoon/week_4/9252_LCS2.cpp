#include<iostream>
#include<string>
#include<vector>
using namespace std;
int dp[1002][1002]={0,};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<char> v;
  string s1, s2; cin >> s1 >> s2;
  int n1=s1.size(), n2=s2.size();
  for(int i=1; i<=s1.size(); i++) {
    for(int j=1; j<=s2.size(); j++) {
      if(s1[i-1] == s2[j-1]) 
        dp[i][j] = dp[i-1][j-1]+1;
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  cout << dp[n1][n2] << '\n';
  int i=n1, j=n2;
  while(dp[i][j]) {
    if(dp[i][j] == dp[i-1][j])
      i--;
    else if(dp[i][j] == dp[i][j-1])
      j--;
    else{
      v.push_back(s1[i-1]);
      i--;
      j--;
    }
  }
  for(int i=v.size()-1; i>=0; i--)
    cout << v[i];
}