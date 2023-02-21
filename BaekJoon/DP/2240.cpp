#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int t, w, dp[1004][3][34], b[1004];

int func(int idx, int tree, int cnt) {
  // 기저조건
  if(cnt < 0) return 0;

  // 메모이제이션
  if(dp[idx][tree][cnt]!=-1) return dp[idx][tree][cnt];

  // 로직
  if(tree == 1) return dp[idx][tree][cnt] = max(func(idx+1, 2, cnt-1), func(idx+1, 1, cnt)) + (tree==b[idx]);
  return dp[idx][tree][cnt] = max(func(idx+1, 1, cnt-1), func(idx+1, 2, cnt)) + (tree==b[idx]);
}

int main() {
  cin >> t >> w;
  for(int i=0; i<t; i++) cin >> b[i];
  memset(dp, -1, sizeof(dp));
  cout << max(func(0, 2, w-1), func(0, 1, w));
}