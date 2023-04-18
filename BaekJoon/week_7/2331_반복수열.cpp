#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int a, p, ans;
vector<int> v;

int check(int n) {
  for(int i=0; i<v.size(); i++)
    if(v[i] == n){
      ans = i;
      return i;
    }
  
  return -1;
}

int func(int n, int p) {
  int result=0;
  while(n) {
    result += round(pow(n%10, p));
    n /= 10;
  }
  return result;
}

int main() {
  cin >> a >> p;
  
  while(check(a) == -1){
    v.push_back(a);
    a = func(a, p);
  }

  cout << ans;
}

// 같은 숫자가 하나라도 있으면 무조건 반복된다.
// pow 쓰면 오차가 일어나는 경우가 있음 -> round로 해결