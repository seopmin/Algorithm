#include<iostream>
#include<algorithm>
#include<cmath>
#include<limits.h>
#include<vector>
using namespace std;
int n, map[21][21], a[21], res=INT_MAX;

void func2() {
  vector<int> v1;
  vector<int> v2;

  for(int i=0; i<n; i++) {
    if(a[i]) v1.push_back(i);
    else v2.push_back(i);
  }

  int v1_sum=0, v2_sum=0;
  for(int i=0; i<v1.size(); i++) {
    for(int j=0; j<v1.size(); j++) {
      v1_sum += map[v1[i]][v1[j]];
      v2_sum += map[v2[i]][v2[j]];
    }
  }
  res = min(res, abs(v1_sum-v2_sum));
}

void func(int cnt, int pos) {
  if(cnt == n/2) {
    func2();
    return;
  }
  for(int i=pos; i<n; i++) {
    if(a[i]) continue;
    a[i]=1;
    func(cnt+1, i);
    a[i]=0;
  }
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> map[i][j];

  func(0, 0);
  
  cout << res;
}