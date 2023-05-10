#include<iostream>
using namespace std;
int time_l[101];

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int n=3, l, r;
  while(n--) {
    cin >> l >> r;
    for(int i=l+1; i<=r; i++)
      time_l[i]++;
  }
  int sum=0;
  for(int i=0; i<101; i++) {
    if(time_l[i]==1)
      sum += a;
    else if(time_l[i]==2)
      sum += 2*b;
    else if(time_l[i]==3)
      sum += 3*c;
  }
  cout << sum;
}