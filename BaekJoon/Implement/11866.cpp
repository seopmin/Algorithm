#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n, k; cin >> n >> k;

  vector<int> v;
  for(int i=1; i<=n; i++) {
    v.push_back(i);
  }
  int idx = k-1;

  cout << "<";
  while(v.size()!=1) {
    if(idx >= v.size()) {
      idx = idx % (v.size());
    }
    cout << v[idx] << ", ";
    v.erase(v.begin()+idx);
    idx-=1;
    idx += k;
  }
  cout << v[0] << ">";
}