#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
int a, b, arr[8][8], result=0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void copy(int temp[][8], int arr[][8]) {
  for(int i=0; i<a; i++) {
    for(int j=0; j<b; j++) {
      temp[i][j] = arr[i][j];
    }
  }
}

int bfs() {
  queue<pair<int, int>> q;
  for(int i=0; i<a; i++) {
    for(int j=0; j<b; j++) {
      if(arr[i][j]==2) {
        q.push({i,j});
      }
    }
  }
  while(q.size()) {
    int x, y; 
    tie(x,y)=q.front(); q.pop();
    for(int i=0; i<4; i++) {
      int ny = x+dx[i];
      int nx = y+dy[i];
      if(nx>=0 && ny>=0 && nx<b && ny<a && arr[ny][nx]==0) {
        arr[ny][nx]=2;
        q.push({ny, nx});
      }
    }
  }
  int sum=0;
  for(int i=0; i<a; i++) {
    for(int j=0; j<b; j++) {
      if(arr[i][j]==0) {
        sum += 1;
      }
    }
  }
  return sum;
}

void wall(int cnt) {
  if(cnt==3) {
    int temp[8][8];
    copy(temp, arr);
    result = max(result, bfs());
    copy(arr, temp);
    return;
  }

  for(int i=0; i<a; i++) {
    for(int j=0; j<b; j++) {
      if(arr[i][j]==0) {
        arr[i][j]=1;
        wall(cnt+1);
        arr[i][j]=0;
      }
    }
  }
}

int main() {
  cin >> a >> b;
  for(int i=0; i<a; i++)
    for(int j=0; j<b; j++)
      cin >> arr[i][j];

  for(int i=0; i<a; i++) {
    for(int j=0; j<b; j++) {
      if(arr[i][j]==0) {
        arr[i][j] = 1;
        wall(1);
        arr[i][j] = 0;
      }
    }
  }

  cout << result;
}