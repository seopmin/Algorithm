#include<iostream>
using namespace std;
int r, c, k, visited[6][6], result=0;
char map[6][6];

void dfs(int x, int y, int cnt) {
  if(x==c-1 && y==0) { 
    if(cnt==k) result++;
    return ; 
  }
  if(x<0 || y<0 || x>=c || y>=r || visited[y][x] || map[y][x]=='T') return ;
  visited[y][x]=1;
  dfs(x, y+1, cnt+1);
  dfs(x, y-1, cnt+1);
  dfs(x+1, y, cnt+1);
  dfs(x-1, y, cnt+1);
  visited[y][x]=0;
}

int main() {
  cin >> r >> c >> k;
  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
      cin >> map[i][j];

  dfs(0,r-1,1);
  cout << result;
}