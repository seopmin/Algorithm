#include<iostream>
#include<vector>
#include<string>
using namespace std;
string arr[5][5];
vector<string> v;

void dfs(int y, int x, string k, int depth) {
  if(depth==6){
    for(int i=0; i<v.size(); i++)
      if(k==v[i])
        return;
    v.push_back(k);
    return;
  }
  if(x<0 || y<0 || x>=5 || y>=5) return;

  k += arr[y][x];
  dfs(y+1, x, k, depth+1);
  dfs(y-1, x, k, depth+1);
  dfs(y, x+1, k, depth+1);
  dfs(y, x-1, k, depth+1);
}

int main() {
  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
      cin >> arr[i][j];

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
      dfs(i, j, "", 0);
      
  cout << v.size();
}