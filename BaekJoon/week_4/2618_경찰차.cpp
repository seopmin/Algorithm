#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, w; 
vector<pair<int, int>> v;
vector<int> result;
int dp[1001][3]={};

int min_func(int d, pair<int, int> p1, pair<int, int> p2) {
  if(d>=w) return 0;
  if(dp[d][1]&&dp[d][2]) return min(dp[d][1], dp[d][2]);


  // int a = min_func(h+1, {v[h].first, v[h].second}, p2)+abs(p1.first-v[h].first) + abs(p1.second-v[h].second);
  // int b = min_func(h+1, p1, {v[h].first, v[h].second})+abs(p2.first-v[h].first) + abs(p2.second-v[h].second);

  // if(a <= b){
  //   dp[h] = a;
  // } else {
  //   dp[h] = b;
  // }
  // dp[h] = min(a, b);
  // return dp[h];

  // int a = abs(p1.first-v[h].first) + abs(p1.second-v[h].second);
  // int b = abs(p2.first-v[h].first) + abs(p2.second-v[h].second);
  // if(!dp[a][b])
  //   dp[a][b] = min_func(a, b, {v[a].first, v[a].second}, p2)+abs(p1.first-v[a].first) + abs(p1.second-v[a].second);
  
  // if(!dp[a][b])
  //   dp[a][b] = min_func(a, b, p1, {v[b].first, v[b].second})+abs(p2.first-v[b].first) + abs(p2.second-v[b].second);

  int a = min_func(d+1, {v[d].first, v[d].second}, p2)+abs(p1.first-v[d].first) + abs(p1.second-v[d].second);
  int b = min_func(d+1, p1, {v[d].first, v[d].second})+abs(p2.first-v[d].first) + abs(p2.second-v[d].second);
  
  if(a < b) {
    result[d]=1;
    return a;
  } else {
    result[d]=2;
    return b;
  }

  // if(dp[a][b] < dp[a][b]){
  //   result[a] = 1;
  //   return dp[a][b];
  // } else {
  //   result[b] = 2;
  //   return dp[a][b];
  // }
  

  //dp[h] = min(min_func(h+1, {v[h].first, v[h].second}, p2)+abs(p1.first-v[h].first) + abs(p1.second-v[h].second), min_func(h+1, p1, {v[h].first, v[h].second})+abs(p2.first-v[h].first) + abs(p2.second-v[h].second));
  

  // int a = abs(p1.first-v[h].first) + abs(p1.second-v[h].second);
  // int b = abs(p2.first-v[h].first) + abs(p2.second-v[h].second);

  // dp[h] = min(min_func(h+1, {v[h].first, v[h].second}, p2)+a, min_func(h+1, p1, {v[h].first, v[h].second})+b);

  // return dp[h];



  // int a = abs(p1.first-x) + abs(p1.second-y);
  // int b = abs(p2.first-x) + abs(p2.second-y);
  // if(a < b) {

  // }
}
int main() {
  cin >> n >> w;
  pair<int, int> p1={1,1}, p2{n,n};

  for(int i=0; i<w; i++) {
    int x, y; cin >> x >> y;
    v.push_back({x, y});
    result.push_back(0);
  }

  cout << min_func(0, p1, p2) << endl;
  for(int i=0; i<w; i++) {
    cout << result[i] << endl;
  }
  
}