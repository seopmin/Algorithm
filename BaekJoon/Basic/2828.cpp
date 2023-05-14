#include<iostream>
using namespace std;
int apple[21];
int main() {
  int n, m, j; cin >> n >> m >> j;
  int l_pos=1, r_pos=m, result=0, k;
  for(int i=0; i<j; i++) {
    cin >> apple[i];
    if(apple[i]>r_pos) {
      k = apple[i]-r_pos;
      result += k;
      r_pos+=k;
      l_pos+=k;
    } else if(apple[i]<l_pos) {
      k = l_pos-apple[i];
      result += k;
      l_pos-=k;
      r_pos-=k;
    }
  }
  cout << result;
}