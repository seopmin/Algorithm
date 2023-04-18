#include<iostream>
#include<vector>
using namespace std;

void func(int a, int b) {
  vector<int> idx(a);
  vector<int> v(a);
  idx[b]=1;
  int cnt = 0;
  for(int i=0; i<a; i++) {
    cin >> v[i];
  }
  while(v.size()) {
    int discern = 1;
    for(int i=1; i<v.size(); i++) {
      if(v[0]<v[i]) {
        discern = 0;
        break;
      }
    }
    if(discern == 0) {
      idx.push_back(idx[0]);
      idx.erase(idx.begin());
      v.push_back(v[0]);
      v.erase(v.begin());
    } else {
      cnt++;
      if(idx[0] == 1) {
        cout << cnt << endl;
        return;
      }
      idx.erase(idx.begin());
      v.erase(v.begin());
    }
  }
}

int main() {
  int n; cin >> n;
  for(int i=0; i<n; i++) {
    int a, b; cin >> a >> b;
    func(a, b);
  }
}