#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
int n, m, map[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int check() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(map[i][j]==0) return 0;
    }
  }
  return 1;
}

int bfs() {
  queue<tuple<int,int,int>> q;
  int result=0, depth=0;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(map[i][j]==1) {
        q.push({j, i, depth});
      }
    }
  }

  while(q.size()) {
    int x, y; tie(x, y, depth) = q.front(); q.pop();
    if(check()) return result;
    for(int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(nx>=0 && ny>=0 && nx<m && ny<n && map[ny][nx]==0) {
        map[ny][nx]=1;
        q.push({nx, ny, depth+1});
        result=max(result, depth+1);
      }
    } 
    
  }

  return -1;
}

int main() {
  cin >> m >> n;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> map[i][j];
    }
  }
  
  cout << bfs();
}


// #include<iostream>
// #include<queue>
// #include<tuple>
// #include<algorithm>
// using namespace std;
// int n, m, map[1001][1001];
// int dx[] = {0,0,1,-1};
// int dy[] = {1,-1,0,0};
// queue<pair<int,int>> q;


// void bfs() {

//   while(q.size()) {
    
//     int x, y; tie(x, y) = q.front(); q.pop();
//     for(int i=0; i<4; i++) {
//       int nx = x+dx[i];
//       int ny = y+dy[i];

//       if(nx>=0 && ny>=0 && nx<m && ny<n && map[ny][nx]==0) {
//         map[ny][nx]= map[y][x]+1;
//         q.push({nx, ny});
//       }
//     } 
    
//   }
// }

// int main() {
//   cin >> m >> n;

//   for(int i=0; i<n; i++) {
//     for(int j=0; j<m; j++) {
//       cin >> map[i][j];
//       if(map[i][j]==1){
//         q.push({j,i});
//       }
//     }
//   }
  
//   bfs();

//   int sum=0;
//   for(int i=0; i<n; i++) {
//     for(int j=0; j<m; j++) {
//       if(map[i][j]==0) {
//         cout << -1;
//         return 0;
//       }
//       sum = max(sum, map[i][j]);
//     }
//   }
//   cout << sum-1;
// }