#include<iostream>
#include<algorithm>
using namespace std;
int n, result=0, arr[10][10], visited[10][10]={};

int cnt() {
  int sum=0;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(visited[i][j]==1) sum += 1;
  
  return sum;
}

int check(int x, int y) {
  int copy_x=x, copy_y=y;
  while(copy_x && copy_y) {
    if(visited[copy_y][copy_x] || !arr[copy_y][copy_x])
      return 0;
    copy_y--;
    copy_x--;
  }
  copy_x=x, copy_y=y;
  while(copy_x<n && copy_y) {
    if(visited[copy_y][copy_x] || !arr[copy_y][copy_x])
      return 0;
    copy_y--;
    copy_x++;
  }
  copy_x=x, copy_y=y;
  while(copy_x && copy_y<n) {
    if(visited[copy_y][copy_x] || !arr[copy_y][copy_x])
      return 0;
    copy_y++;
    copy_x--;
  }
  copy_x=x, copy_y=y;
  while(copy_x<n && copy_y<n) {
    if(visited[copy_y][copy_x] || !arr[copy_y][copy_x])
      return 0;
    copy_y++;
    copy_x++;
  }

  cout << "depth :" << copy_y <<endl;
  return 1;
}

void dfs(int depth) {
  if(depth==n) {
    result = max(result, cnt());
    return;
  }

  for(int i=0; i<n; i++) {
    if(check(i, depth) && !arr[depth][i])
      visited[depth][i]=1;

    dfs(depth+1);
    visited[depth][i]=0;
  }
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> arr[i][j];

  dfs(0);
  cout << result;

}