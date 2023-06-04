#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, p, d, result=0;
priority_queue<int, vector<int>, less<int>> q;
vector<pair<int, int>> v;

bool comp(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}

int main() {
  cin >> n;
  if(n==0) { cout << 0; return 0; }
  
  for(int i=0; i<n; i++) {
    cin >> p >> d;
    v.push_back({p, d});
  }
  sort(v.begin(), v.end(), comp);

  for(int current_d=v[0].second, j=0; current_d>0; current_d--) {
    while(j<v.size() && v[j].second==current_d) {
      q.push(v[j].first);
      j++;
    }

    if(q.size()) {
      result += q.top();
      q.pop();
    }
  }

  cout << result;
}