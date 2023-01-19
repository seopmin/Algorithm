#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m, b, input, low=256, high=0; cin >> n >> m >> b;
  int arr[257] = { };
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++){
      cin >> input;
      arr[input]++;
      low = min(low, input);
      high = max(high, input);
    }
  }

  int result = INT_MAX, bl;
  for(int x=low; x<=high; x++) {
    int use=0; int get=0;
    for(int i=0; i<x; i++) use += (x-i)*arr[i];
    for(int i=256; i>x; i--) get += (i-x)*arr[i];

    int total = use+2*get;
    if(use <= get+b) {
      if(total <= result) {
        result = total;
        bl = x;
      }
    }
  }
  cout << result << ' ' << bl;
}