#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int usable[]={1,1,1,1,1,1,1,1,1,1};

int dis(int n) {
  if(n==0){
    if(usable[n]==0)
      return -1;
    return 1;
  }
  int len = 0;
  while(n) {
    int temp=n%10;
    if(usable[temp]==0){
      return -1;
    }
    n /= 10;
    len++;
  }
  return len;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m, input; cin >> n >> m;
  int result = abs(n-100);
  for(int i=0; i<m; i++) {
    cin >> input;
    usable[input]=0;
  }
  
  int cnt;

  for(int i=0; i<= 1000000; i++) {
    cnt = dis(i);
    if(cnt > 0) {
      if(result > abs(i-n)+cnt) {
        result = abs(i-n)+cnt;
      }
    }
  }
  cout << result;
}