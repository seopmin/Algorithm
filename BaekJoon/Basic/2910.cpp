#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
vector<tuple<int, int, int>> v;

bool comp(tuple<int, int, int> a, tuple<int, int, int> b) {
  if(get<1>(a) == get<1>(b))
    return get<2>(a) < get<2>(b);
  
  return get<1>(a) > get<1>(b);
}

int main() {
  int n, c; cin >> n >> c;

  for(int i=0; i<n; i++) {
    int k, dis=1; cin >> k;
    for(int i=0; i<v.size(); i++) {
      if(get<0>(v[i]) == k) {
        get<1>(v[i])++;
        dis=0;
      }
    }
    if(dis) {
      v.push_back({k, 1, i});
    }
  }
  sort(v.begin(), v.end(), comp);

  for(int i=0; i<v.size(); i++) {
    for(int j=0; j<get<1>(v[i]); j++) {
      cout << get<0>(v[i]) << ' ';
    }
  }
}