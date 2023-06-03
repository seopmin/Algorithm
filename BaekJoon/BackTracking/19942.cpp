#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
int n, mp, mf, ms, mv, val[20][5], min_result=INT_MAX;
vector<vector<int>> ans;

void func(int st, vector<int> idx) {
  int p=0,f=0,s=0,v=0,price=0;
  for(auto i : idx) {
    p+= val[i][0];
    f += val[i][1];
    s += val[i][2];
    v += val[i][3];
    price += val[i][4];
  }

  if(p>=mp && f>=mf && s>=ms && v>=mv) {
    if(min_result > price) {
      min_result = price;
      ans.clear();
      ans.push_back(idx);
    } else if(min_result == price) {
      ans.push_back(idx);
    }
  }

  for(int i = st; i<n; i++) {
    idx.push_back(i);
    func(i+1, idx);
    idx.pop_back();
  }
}

int main() {
  cin >> n >> mp >> mf >> ms >> mv;
  for(int i=0; i<n; i++) {
    for(int j=0; j<5; j++) {
      cin >> val[i][j];
    }
  }

  vector<int> idx;
  func(0, idx);
  sort(ans.begin(), ans.end());

  if(min_result==INT_MAX) {
    cout << -1;
  } else {
    cout << min_result << endl;
    for(int i : ans[0]) cout << i+1 << ' ';
  }
}