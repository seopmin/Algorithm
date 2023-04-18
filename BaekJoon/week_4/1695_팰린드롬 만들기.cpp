// 알고리즘 큰 틀 : 투포인터 이용

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[5000];
int dp[5000][5000];
int func(int left, int right) {
  if(left>=right) return 0;
  if(dp[left][right]) return dp[left][right];

  if(arr[left] == arr[right])
    dp[left][right] = func(left+1, right-1);
  else
    dp[left][right] = min(func(left, right-1)+1, func(left+1, right)+1);

  return dp[left][right];
}

int main() {
  int n; cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];
  cout << func(0, n-1);
}