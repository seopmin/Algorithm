#include<iostream>
using namespace std;
int n,m, map[501][501], dp[501][501], visited[501][501];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

int DP(int y, int x) {
  if(y==1 && x==1) return 1;
  if(visited[y][x]) return dp[y][x];
  visited[y][x]=1;

  for(int i=0; i<4; i++) {
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>0 && ny>0 && nx<=m && ny<=n) {
      if(map[y][x] < map[ny][nx])
        dp[y][x] += DP(ny, nx);
    }
  }
  return dp[y][x];
}

int main() {
  cin >> n >> m;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      cin >> map[i][j];

  cout << DP(n, m);
}

// #include<iostream>
// using namespace std;
// int n, m, map[501][501], dp[501][501], visited[501][501];
// int dx[] = {0,0,1,-1};
// int dy[] = {1,-1,0,0};

// int DP(int i, int j) {
//   if(i==1 && j==1) return 1;
//   if(visited[i][j]) return dp[i][j];
//   visited[i][j]=1;
//   for(int k=0; k<4; k++) {
//     int y=i+dy[k];
//     int x=j+dx[k];
//     if(x>0 && y>0 && y<=n && x<=m){
//       if(map[i][j]<map[y][x]) {
//         dp[i][j] += DP(y, x);
//       }
//     }
//   }
//   return dp[i][j];
// }

// int main() {
//   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   cin >> n >> m;
//   for(int i=1; i<=n; i++)
//     for(int j=1; j<=m; j++)

//       cin >> map[i][j];

//   cout << DP(n, m);
// }




/* 실패 */
// #include<iostream>
// #include<limits.h>
// using namespace std;
// int n, m;
// long long map[502][502], dp[502][502];

// int main() {
//   cin >> n >> m;
//   for(int i=1; i<=n; i++)
//     for(int j=1; j<=m; j++)
//       cin >> map[i][j];
  
//   map[1][0] = INT_MAX;
//   dp[1][0]=1;
//   for(int i=1; i<=n; i++) {
//     for(int j=1; j<=m; j++) {
//       long long temp=0;
//       if(map[i][j]<map[i-1][j]) {
//         temp += dp[i-1][j];
//       }
//       if(map[i][j]<map[i+1][j]) {
//         temp += dp[i+1][j];
//       }
//       if(map[i][j]<map[i][j-1]) {
//         temp += dp[i][j-1];
//       }
//       if(map[i][j]<map[i][j+1]) {
//         temp += dp[i][j+1];
//       }
//       dp[i][j] = temp;
//     }
//   }

//   for(int i=1; i<=n; i++) {
//     for(int j=1; j<=m; j++) {
//       long long temp=0;
//       if(map[i][j]<map[i-1][j]) {
//         temp += dp[i-1][j];
//       }
//       if(map[i][j]<map[i+1][j]) {
//         temp += dp[i+1][j];
//       }
//       if(map[i][j]<map[i][j-1]) {
//         temp += dp[i][j-1];
//       }
//       if(map[i][j]<map[i][j+1]) {
//         temp += dp[i][j+1];
//       }
//       dp[i][j] = temp;
//     }
//   }

//   // for(int i=1; i<=n; i++) {
//   //   for(int j=1; j<=m; j++) {
//   //     cout << dp[i][j] << ' ';
//   //   }
//   //    cout << endl;
//   // }
//   cout << dp[n][m];
// }