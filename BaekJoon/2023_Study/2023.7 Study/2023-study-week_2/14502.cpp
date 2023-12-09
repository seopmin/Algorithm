#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, arr[8][8], result=0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<pair<int, int>> v;

void copy(int temp[][8], int arr[][8]) {
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      temp[i][j] = arr[i][j];
    }
  }
}

int bfs() {
  queue<pair<int, int>> q;
  for(int i=0; i<v.size(); i++)
    q.push({v[i].first, v[i].second});
  
  while(q.size()) {
    int x, y; 
    tie(x,y)=q.front(); q.pop();
    for(int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0 && ny>=0 && nx<m && ny<n && arr[ny][nx]==0) {
        arr[ny][nx]=2;
        q.push({nx, ny});
      }
    }
  }
  int sum=0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(arr[i][j]==0)
        sum += 1;
    }
  }
  return sum;
}

void wall(int cnt) {
  if(cnt==3) {
    int temp[8][8];
    copy(temp, arr);
    int t = bfs();
    result = max(result, bfs());
    copy(arr, temp);
    return;
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(arr[i][j]==0) {
        arr[i][j]=1;
        wall(cnt+1);
        arr[i][j]=0;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> arr[i][j];
      if(arr[i][j]==2) v.push_back({j, i});
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(arr[i][j]==0) {
        arr[i][j] = 1;
        wall(1);
        arr[i][j] = 0;
      }
    }
  }

  cout << result;
}