#include<iostream>
#include<vector>
using namespace std;
int n, visited[10];
char input[10];
vector<int> v;
vector<int> v_min={9,9,9,9,9,9,9,9,9,9};
vector<int> v_max;

void min_func() {
  if(v.size() < v_min.size()) { v_min = v; return; } 
  for(int i=0; i<v.size(); i++) {
    if(v[i]>v_min[i]) { return; }
    else if(v[i]<v_min[i]) { v_min=v; return; }
  }
}

void max_func() {
  if(v.size() > v_max.size()) { v_max = v; return; } 
  for(int i=0; i<v.size(); i++) {
    if(v[i]<v_max[i]) { return; }
    else if(v[i]>v_max[i]) {v_max=v; return; }
  }
}

void dfs(int k, int cnt) {
  if(cnt == n) {
    min_func();
    max_func();
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
  for(int i=0; i<n; i++)
    cin >> input[i];

  for(int i=0; i<10; i++) {
    v.push_back(i);
    visited[i]=1;
    dfs(i, 0);
    visited[i]=0;
    v.pop_back();
  }
  for(int i=0; i<v_max.size(); i++) cout << v_max[i];
  cout << endl;
  for(int i=0; i<v_min.size(); i++) cout << v_min[i];
}