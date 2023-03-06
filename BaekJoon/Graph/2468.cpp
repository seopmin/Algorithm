#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n, map[101][101];
int visited[101][101];
int over[101][101];
int result=0;

void check_overflow(int k) {
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(map[i][j]<k)
        over[i][j]=1;
}

int dfs(int x, int y) {
  if(x>=0 && y>=0 && x<n && y<n) {
    if(visited[y][x] || over[y][x]) return 0;

    visited[y][x]=1;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
    return 1;
  }
  return 0;
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
    }
  }
  for(int i=1; i<=100; i++) {
    check_overflow(i);
    memset(visited, 0, sizeof(visited));
    int sum=0;
    for(int j=0; j<n; j++)
      for(int w=0; w<n; w++)
        sum+=dfs(w,j);
      
    result=max(result,sum);
  }
  cout << result;
}