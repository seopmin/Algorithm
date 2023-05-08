#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, visited[26][26], cnt;
char map[26][26];
vector<int> v;

void dfs(int x, int y) {
  if(visited[y][x]) return;
  if(x>0 && y>0 && x<=n && y<=n && map[y][x]=='1') {
    visited[y][x]=1;
    cnt++;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
  }
}

int main() {
  cin >> n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin >> map[i][j];
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(map[i][j]=='1' && !visited[i][j]){
        cnt=0;
        dfs(j, i);
        v.push_back(cnt);
      }
    }
  }
  sort(v.begin(), v.end());
  cout << v.size() << endl;
  for(int i=0; i<v.size(); i++) {
    cout << v[i] << endl;
  }
}