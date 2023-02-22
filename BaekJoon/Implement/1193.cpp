#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n; cin >> n;
  int bunmo=1;
  int cnt = 1;
  int discern = 1;
  while(bunmo) {
    
    if(discern==0) {
      int temp = bunmo;
      for(int i=1; i<=bunmo; i++) {
        if(cnt == n) {
          cout << i << '/' << temp;
          return 0;
        }
        temp--;
        cnt++;
      }
      bunmo++;
      discern=1;
    }
    if(discern==1) {
      int temp = 1;
      for(int i=bunmo; i>=1; i--) {
        if(cnt==n) {
          cout << i << '/' << temp;
          return 0;
        }
        temp++;
        cnt++;
      }
      bunmo++;
      discern = 0;
    }
  }
}