#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n, w;
vector<pair<int, int>> v(w);

int func(int i, pair<int, int> p1, pair<int, int> p2) {
  if(i >= w) return 1;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> w;

  pair<int, int> p1 = {1,1}, p2 = {n,n};
  for(int i=0; i<w; i++)
    cin >> v[i].first >> v[i].second;
}