#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;
int n, arr[20][20], result=INT_MAX;
int visited[20]={};

int func() {
  int a=0, b=0;
  for(int i=0; i<n-1; i++) {
    for(int j=i+1; j<n; j++) {
      if(visited[i] && visited[j]) {
        a += arr[i][j]+arr[j][i];
      }else if(!visited[i] && !visited[j]) {
        b += arr[i][j]+arr[j][i];
      }
    }
  }
  return abs(a-b);
}

int dfs(int depth) {
  if(depth == n) return min(result, func());
  visited[depth]=1;
  int a = dfs(depth+1);
  visited[depth]=0;
  int b = dfs(depth+1);
  return min(a, b);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> arr[i][j];

  cout << dfs(0);
}