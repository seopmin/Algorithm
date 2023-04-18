#include<iostream>
#include<string>
using namespace std;
int r, c, result=0;
string s[20];
int visited[26]={0};

void dfs(int x, int y, int depth) {
  if(x<0 || y<0 || x>=r || y>=c || visited[s[x][y]-65]) {
    result=max(result, depth);
    return;
  }
  visited[s[x][y]-65]=1;
  dfs(x-1, y, depth+1);
  dfs(x, y-1, depth+1);
  dfs(x+1, y, depth+1);
  dfs(x, y+1, depth+1);
  visited[s[x][y]-65]=0;
}

int main() {
  cin >> r >> c;
  for(int i=0; i<r; i++)
    cin >> s[i];

  dfs(0, 0, 0);
  cout << result;
}