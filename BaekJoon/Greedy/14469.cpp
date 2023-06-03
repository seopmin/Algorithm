#include<iostream>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
}

int main() {
  int n; cin >> n;
  vector<pair<int, int>> v(n);

  for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;

  sort(v.begin(), v.end(), comp);

  int time=0;
  for(int i=0; i<n; i++) {
    if(time<v[i].first) 
      time = v[i].first+v[i].second;
    else
      time += v[i].second;
  }
  cout << time;
}