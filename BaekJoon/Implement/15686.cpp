// 1. 치킨 거리가 가장 작은 M개의 치킨집을 골라 벡터에 거리 정보만 저장

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