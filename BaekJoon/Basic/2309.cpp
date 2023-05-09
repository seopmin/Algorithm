#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int v[9];
vector<int> v2;
bool visited[10];
int n, k, dis=0;

void print() {
  for(int i=0; i<9; i++) {
    if(visited[i]) {
      v2.push_back(v[i]);
    }
  }
  sort(v2.begin(), v2.end());
  for(int i=0; i<7; i++) {
    cout << v2[i] << endl;
  }
}

void dfs(int cnt, int i, int sum) {
  if(dis) return;
  if(cnt==7 && sum==100) {
    print();
    dis=1;
    return;
  }
  if(cnt>7 || sum >100) return;
  cnt++;
  for(int j=0; j<9; j++) {
    if(visited[j]) continue;
    visited[j]=1;
    dfs(cnt, j, sum+v[j]);
    visited[j]=0;
  }
  
}

int main() {
  for(int i=0; i<9; i++) {
    cin >> v[i];
  }
  for(int i=0; i<9; i++) {
    visited[i]=1;
    int cnt=1;
    dfs(cnt, i, v[i]);
    visited[i]=0;
  }
}