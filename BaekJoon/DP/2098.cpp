#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, W[17][17];
int visited[17];
int dp, last, first;

int DP(int prev) {
  int result=INT_MAX;
  bool dis = true;
  for(int i=1; i<=n; i++) {
    if(!visited[i]) {
      dis = false;
      visited[i]=1;
      dp = W[prev][i]+DP(i);
      visited[i]=0;
      result = min(dp, result);
    }
  }
  if(dis == true) {
    return W[prev][first];
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin >> W[i][j];
    }
  }
  
  first = 1;
  visited[1]=1;
  cout<<DP(1);
}