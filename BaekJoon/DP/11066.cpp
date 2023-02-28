#include<iostream>
#include<algorithm>
#include<string.h>
#include<limits.h>
using namespace std;
int t, k;
int files[501];
int dp[501][501];
int sum[501];

int func(int left, int right) {
  if(left == right){
    return 0;
  }
  if(dp[left][right]){
    return dp[left][right];
  } 
  if(left == right-1) {
    return dp[left][right]=files[left-1]+files[right-1];
  }

  int result = INT_MAX;
  for(int i=left; i<right; i++) {
    int a = func(left, i);
    int b = func(i+1, right);
    result = min(result, a+b);
  }
  return dp[left][right] = result + sum[right-1]-sum[left-2];
}

int main() {
  cin >> t;
  for(int i=0; i<t; i++) {
    cin >> k;
    memset(dp, 0, sizeof(dp));
    for(int j=0; j<k; j++) {
      cin >> files[j];
      sum[j] = sum[j-1]+files[j];
    }
    cout << func(1, k) << endl;;
  }
}