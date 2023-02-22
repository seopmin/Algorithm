#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v1;
vector<int> v2;
int n, k, a, b;

bool comp(pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first && a.second > b.second);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    v1.push_back({a, b});
  }
  sort(v1.begin(), v1.end(), comp);

  for(int i=0; i<k; i++) {
    cin >> a;
    v2.push_back(a);
  }
  sort(v2.begin(), v2.end());

  long long sum=0;
  int idx=0;
  for(int i=0; i<k; i++) {
    while(v2[i])
  }
  
  // for(int i=0; i<k; i++) {
  //   for(int j=0; j<v1.size(); j++) {
  //     if(v2[i] > v1[j].first) {
  //       sum += v1[j].second;
  //       v1.erase(v1.begin()+j);
  //     } 
  //   }
  // }

  cout << sum;
}