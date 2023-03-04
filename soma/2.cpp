#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

int main() {
  int n; cin >> n;
  vector<vector<tuple<int, int, int, int>>> v;
  for(int i=0; i<n; i++) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    vector<tuple<int, int, int, int>> v2;
    v2.push_back({x1,y1,x2,y2});
    v.push_back(v2);
  }


  
}