#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
int n, min_result = INT_MAX, max_result = INT_MIN;
int arr[11], oper_cnt[4];

int cal(int oper_idx, int v, int i) {
  if(oper_idx==0) return v+arr[i];
  if(oper_idx==1) return v-arr[i];
  if(oper_idx==2) return v*arr[i];
  return v/arr[i];
}

void dfs(int depth, int value) {
  if(depth==n) {
    min_result = min(min_result, value);
    max_result = max(max_result, value);
    return;
  }
  for(int i=0; i<4; i++) {
    if(oper_cnt[i] != 0) {
      oper_cnt[i]--;
      dfs(depth+1, cal(i, value, depth));
      oper_cnt[i]++;
    }
  }
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];
  for(int i=0; i<4; i++) cin >> oper_cnt[i];
  dfs(1, arr[0]);
  cout << max_result << '\n' << min_result;
}