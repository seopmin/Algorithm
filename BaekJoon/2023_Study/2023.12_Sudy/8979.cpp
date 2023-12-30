/*
  올림픽
  - gold, silver, bronze 의 배열을 각각 만듦(인덱스 번호가 국가 번호가 됨)
  - 금메달 수가 더 많은 나라 존재? -> result++
  - 금메달 수가 같은데 은메달 수가 더 많은 나라 존재? -> result++
  - 금,은의 수가 같고 동메달 수가 더 많은 나라 존재? -> result++
*/
#include <iostream>
using namespace std;

int g[1001], s[1001], b[1001];
int n, k, t, result;

int main() {
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> t;
    cin >> g[t] >> s[t] >> b[t];
  }

  for(int i=1; i<=n; i++) {
    if(g[i] > g[k]){
      result++;
    } else if(g[i] == g[k]) {
      if(s[i] > s[k]) {
        result++;
      } else if(s[i] == s[k]) {
        if(b[i] > b[k]) {
          result++;
        }
      }
    }
  }

  cout << result+1;
}