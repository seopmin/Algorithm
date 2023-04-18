// #include<iostream>
// #include<algorithm>
// #include<limits.h>
// using namespace std;

// int main() {
//   vector<int> dp{0,0};

//   int n; cin >> n;
//   int i=1;
//   while(n-i >= 1) {
//     i++;
//     int temp=INT_MAX;
//     if(i%3==0)
//       temp = min(temp, dp[i/3]+1);
//     if(i%2==0)
//       temp = min(temp, dp[i/2]+1);
//     temp = min(temp, dp[i-1]+1);
//     dp.push_back(temp);
//   }
//   cout << dp[n];
// }

#include<iostream>
using namespace std;
int f(int k) {
  if(k<=1) return 0;
  int f1=f(k/3)+k%3+1;
  int f2=f(k/2)+k%2+1;
  return f1<f2?f1:f2;
}

int main() {
  int n; cin >> n;
  cout << f(n);
}