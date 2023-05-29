#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> v;
vector<int> result[10];

void func(int l, int r, int depth) {
  int m = (l+r)/2;
  if(l==m) { result[depth].push_back(v[m]); return; }
  result[depth].push_back(v[m]);
  func(l, m-1, depth+1);
  func(m+1, r, depth+1);
}

int main() {
  int n, k; cin >> n;
  for(int i=0; i<pow(2, n)-1; i++) { cin >> k; v.push_back(k); }

  func(0, pow(2, n)-2, 0);
  for(int i=0; i<n; i++) {
    for(int j=0; j<result[i].size(); j++)
      cout << result[i][j] << ' ';
    cout << endl;
  }
}