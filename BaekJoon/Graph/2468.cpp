// #include<iostream>
// #include<string.h>
// #include<algorithm>
// using namespace std;
// int n, map[101][101];
// int visited[101][101];
// int over[101][101];
// int result=0;

// void check_overflow(int k) {
//   for(int i=0; i<n; i++)
//     for(int j=0; j<n; j++)
//       if(map[i][j]<k)
//         over[i][j]=1;
// }

// int dfs(int x, int y) {
//   if(x>=0 && y>=0 && x<n && y<n) {
//     if(visited[y][x] || over[y][x]) return 0;

//     visited[y][x]=1;
//     dfs(x+1, y);
//     dfs(x-1, y);
//     dfs(x, y+1);
//     dfs(x, y-1);
//     return 1;
//   }
//   return 0;
// }

// int main() {
//   cin >> n;
//   for(int i=0; i<n; i++) {
//     for(int j=0; j<n; j++) {
//       cin >> map[i][j];
//     }
//   }
//   for(int i=1; i<=100; i++) {
//     check_overflow(i);
//     memset(visited, 0, sizeof(visited));
//     int sum=0;
//     for(int j=0; j<n; j++)
//       for(int w=0; w<n; w++)
//         sum+=dfs(w,j);
      
//     result=max(result,sum);
//   }
//   cout << result;
// }


#include<iostream>
#include<algorithm>
using namespace std;
int n, map[101][101], visited[101][101];

void init() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      visited[i][j]=0;
    }
  }
}

void dfs(int x, int y, int h) {
  if(map[y][x]<=h || visited[y][x]) return;
  if(x<0 || y<0 || x>=n || y>=n) return;
  visited[y][x]=1;
  dfs(x+1, y, h);
  dfs(x-1, y, h);
  dfs(x, y+1, h);
  dfs(x, y-1, h);
}

int solve(int h) {
  int cnt=0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(!visited[i][j] && map[i][j] > h) {
        dfs(j, i, h);
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
    }
  }
  
  int result = 1;
  for(int i=1; i<=100; i++) {
    result = max(result, solve(i));
    init();
  }
  cout << result;
}