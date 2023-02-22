#include<iostream>
#include<vector>
using namespace std;
vector<int> v;

int main() {
  int n; cin >> n;
  for(int i=0; i<n; i++) {
    int k; cin >> k;
    v.push_back(k);
  }

  for(int i=0; i<v.size(); i++) {
    if(v[i]==0) {
      v.erase(v.begin()+i);
      i--;
      v.erase(v.begin()+i);
      i--;
    }    
  }
  v.push_back(0);

  long long sum=0;
  for(int i=0; i<v.size(); i++) {
    sum += v[i];
  }
  cout << sum;
}