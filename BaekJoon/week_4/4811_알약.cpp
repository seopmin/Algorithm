#include<iostream>
using namespace std;

long long dp[31][31];
long long func(int w, int h) {
  if (w==0 && h==0) return 1;
  if(dp[w][h] )return dp[w][h];
  long long *k = &dp[w][h];
  if(w>0) *k += func(w-1, h+1);
  if(h>0) *k += func(w, h-1);
  return *k;
} 

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n;
  while(1) {
    cin >> n; if(n==0) break;
    cout << func(n, 0) << '\n';
  }
}