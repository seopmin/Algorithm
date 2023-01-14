#include<iostream>
using namespace std;

int main() {
   int a, b, cnt=1; cin >> a >> b;
   while(a<b) {
      cnt++;
      if(b%10 == 1)
         b /= 10;
      else if(b%2 != 0)
         break;
      else 
         b /= 2;
   }
   if(a==b) cout << cnt;
   else cout << -1;
}