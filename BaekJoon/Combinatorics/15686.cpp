#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<cstdlib>
#include<limits.h>
using namespace std;
int n, m, h_x, h_y, c_x, c_y, map[51][51], select_c[14], result=INT_MAX;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int func() {
  int sum=0;
  for(int i=0; i<home.size(); i++) {
    tie(h_x, h_y) = home[i];
    int distance=INT_MAX;
    for(int j=0; j<14; j++) {
      if(select_c[j] == 1) {
        tie(c_x, c_y) = chicken[j];
        distance = min(distance, abs(h_x-c_x)+abs(h_y-c_y));
      }
    }
    sum += distance;
  }
  return sum;
}

void combi(int cnt, int k) {
  if(cnt==m) {
    result = min(result,func());
    return;
  }

  for(int i=k+1; i<chicken.size(); i++) {
    select_c[i]=1;
    combi(cnt+1, i);
    select_c[i]=0;
  }
}

int main() {
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
      if(map[i][j]==1) home.push_back({j, i});
      else if(map[i][j]==2) chicken.push_back({j, i});
    }
  }
  
  for(int i=0; i<chicken.size(); i++) {
    select_c[i]=1;
    combi(1, i);
    select_c[i]=0;
  }
  cout << result;
}



// #include<iostream>
// #include<vector>
// #include<tuple>
// #include<queue>
// #include<string.h>
// #include<algorithm>
// #include<limits.h>
// using namespace std;
// int n, m, x, y, a, b, c, map[51][51], select_chi[51][51], chicken_cnt=0;
// vector<pair<int, int>> chicken;
// vector<pair<int, int>> home;
// int visited[51][51];
// int dx[] = {0,0,1,-1};
// int dy[] = {1,-1,0,0};
// int result = INT_MAX;

// // int bfs(pair<int, int> k) {
// //   queue<tuple<int, int, int>> q;
// //   q.push({k.first, k.second, 0});
// //   visited[k.second][k.first] = 1;
// //   while(q.size()) {
// //     tie(a, b, c) = q.front(); q.pop();
// //     // cout << "a: " << a <<", b:" << b<< endl;
// //     if(map[b][a]==2 && select_chi[b][a]) {
// //       return c;
// //     }
// //     for(int i=0; i<4; i++) {
// //       int n_a = a+dx[i];
// //       int n_b = b+dy[i];
// //       if(n_a>=0 && n_b>=0 && n_a<n && n_b<n && !visited[n_b][n_a]) {
// //         visited[n_b][n_a]=1;
// //         q.push({n_a, n_b, c+1});
// //       }
// //     }
// //   }
// //   return -1;
// // }

// void func(int cnt, int w) {
//   if(cnt==0) {
//     // cout << "chicken index" << endl;
//     for(int i=0; i<n; i++) {
//       for(int j=0; j<n; j++) {
//         if(map[i][j]==2 && select_chi[i][j]) {
//           // cout << "(" << j << ", " << i << ") ";
//         }
//       }
//     }
//     // cout << endl;
//     int sum=0;
//     for(int i=0; i<home.size(); i++) {
//       sum+=bfs(home[i]);
//       memset(visited, 0, sizeof(visited));
//     }
//     // cout << endl;
//     // cout << "sum: " << sum << endl;
//     result = min(result, sum);
//     return;
//   }
  
//   for(int j=w+1; j<chicken.size(); j++) {
//     tie(x,y) = chicken[j];
//     if(select_chi[y][x]) continue;
//     select_chi[y][x] = 1;
//     func(cnt-1, j);
//     select_chi[y][x] = 0;
//   }
  

// }

// int main() {
//   cin >> n >> m;
//   for(int i=0; i<n; i++) {
//     for(int j=0; j<n; j++) {
//       cin >> map[i][j];
//       if(map[i][j] == 2) {
//         chicken.push_back({j, i});
//         chicken_cnt++;
//       } else if(map[i][j] == 1) {
//         home.push_back({j, i});
//       }
//     }
//   }
//   for(int i=0; i<chicken.size(); i++) {
//     tie(x,y) = chicken[i];
//     select_chi[y][x]=1;
//     func(m-1, i);
//     select_chi[y][x]=0;
//   }
//   cout << result;
// }