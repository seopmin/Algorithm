#include<iostream>
#include<vector>
#include<algorithm>
<<<<<<< HEAD
#include<cmath>
using namespace std;
int n, w;
vector<pair<int, int>> v(w);

int func(int i, pair<int, int> p1, pair<int, int> p2) {
  if(i >= w) return 1;
=======
#include<cstring>
using namespace std;
int n, w; 
vector<pair<int, int>> loc;
vector<int> result;
int dp[1001][1001]={};

int Find_Dist(int x, int y, int xx, int yy) { return abs(xx - x) + abs(yy - y); }

int func(int p1, int p2) {
  if(p1==w || p2==w) return 0;
  if(dp[p1][p2] != -1) return dp[p1][p2];

  int next = max(p1, p2) + 1;
  
  int a, b;
  a = (p1==0) ? (abs(1-loc[next].first)+abs(1-loc[next].second)) : (abs(loc[p1].first-loc[next].first)+abs(loc[p1].second-loc[next].second));
  
  b = (p2==0) ? (abs(n-loc[next].first)+abs(n-loc[next].second)) : (abs(loc[p2].first-loc[next].first)+abs(loc[p2].second-loc[next].second));
 

  int result1 = func(p1, next) + b;
  int result2 = func(next, p2) + a;
  if(result1 < result2){
    result[next-1]=2;
    dp[p1][p2] = result1;
  } else {
    result[next-1]=1;
    dp[p1][p2] = result2;
  }
  return dp[p1][p2];
>>>>>>> 44e16823e58db84dc73db2f4d1d252bb3ef9b559
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> w;
<<<<<<< HEAD

  pair<int, int> p1 = {1,1}, p2 = {n,n};
  for(int i=0; i<w; i++)
    cin >> v[i].first >> v[i].second;
}
=======
  pair<int, int> p1={1,1}, p2{n,n};

  loc.push_back({0,0});
  for(int i=0; i<w; i++) {
    int x, y; cin >> x >> y;
    loc.push_back({x, y});
    result.push_back(0);
  }

  memset(dp, -1, sizeof(dp));

  cout << func(0, 0) << endl;
  for(int i=0; i<w; i++) {
    cout << result[i] << endl;
  }
  
}


  // if(d>=w) return 0;
  // if(dp[d][1] && dp[d][2]) return min(dp[d][1], dp[d][2]);

  // int a = min_func(d+1, {v[d].first, v[d].second}, p2)+abs(p1.first-v[d].first) + abs(p1.second-v[d].second);
  // int b = min_func(d+1, p1, {v[d].first, v[d].second})+abs(p2.first-v[d].first) + abs(p2.second-v[d].second);
  
  // if(a < b) {
  //   result[d]=1;
  //   return a;
  // } else {
  //   result[d]=2;
  //   return b;
  // }
>>>>>>> 44e16823e58db84dc73db2f4d1d252bb3ef9b559
