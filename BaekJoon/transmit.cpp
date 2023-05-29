#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<cmath>
using namespace std;
int n, visited[10], min_e=INT_MAX, max_e=INT_MIN;
char input[10];
vector<int> v;

void func() {
  int temp=0;
  for(int i=0; i<v.size(); i++) {
    temp *= 10;
    temp += v[i];
  }
  min_e = min(temp, min_e);
  max_e = max(temp, max_e);
}

void dfs(int k, int cnt) {
  if(cnt == n) {
    func();
    return;
  }
  for(int i=0; i<10; i++) {
    if(visited[i]) continue;
    if(input[cnt]=='<' && k>i) continue;
    if(input[cnt]=='>' && k<i) continue;
    v.push_back(i);
    visited[i]=1;
    dfs(i, cnt+1);
    visited[i]=0;
    v.pop_back();
  }
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> input[i];
  }

  for(int i=0; i<10; i++) {
    v.push_back(i);
    visited[i]=1;
    dfs(i, 0);
    visited[i]=0;
    v.pop_back();
  }
  if(max_e/(int)pow(10, n)) cout << max_e << '\n';
  else cout << 0 << max_e << '\n';
  if(min_e/(int)pow(10, n)) cout << min_e;
  else cout << 0 << min_e;
}