#include<iostream>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  
  int s=1, a=1, b=1;
  for(int i=1; i<=n; i++) {
    s *= i;
    if(i==k) a = s;
    if(i==n-k) b = s;
  }

  cout << (s / a) / b;
}