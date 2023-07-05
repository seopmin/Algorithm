#include<iostream>
using namespace std;
int n, a[1000001], b, c;
long long cnt;

int main() {
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  cin >> b >> c;

  cnt = n; // 초기 감독관 수를 테스트 사이트의 수로 설정

  for(int i=0; i<n; i++) {
    a[i] -= b; // 일반 감독관이 감독할 수 있는 인원(b)을 지원자 수에서 뺌

    if(a[i] > 0) {
      // 만약 남은 지원자 수(a[i])가 0보다 크다면
      // 부감독관이 필요한 경우이므로 cnt를 증가시킴
      cnt += a[i] / c; // 남은 지원자 수를 부감독관이 감독할 수 있는 인원(c)로 나눈 몫을 cnt에 더함

      if(a[i] % c)
        cnt++; // 만약 나머지가 있다면, 나머지만큼의 인원을 추가로 감독할 부감독관이 필요하므로 cnt를 1 증가시킴
    }
  }

  cout << cnt; // 필요한 최소 감독관 수를 출력

  return 0;
}