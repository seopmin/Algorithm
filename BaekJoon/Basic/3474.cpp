#include<iostream>
using namespace std;
int n, k, sum, i;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >>n; 
  while(n--) {
    cin >> k;
    sum=0;
    for(i=5; i<=k; i*=5) {
      sum+=k/i;
    }
    cout << sum << '\n';
  }
}