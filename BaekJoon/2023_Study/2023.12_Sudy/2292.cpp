/* 
  첫번째 단계에서의 숫자 범위: 1  (1개))
  두번째 단계에서의 숫자 범위: 2~7  (6개)
  세번째 단계에서의 숫자 범위: 8~19  (12개)
  네번째 단계에서의 숫자 범위: 20~37  (18개)

  숫자의 범위가 6씩 증가 => temp = temp + 6
  각 단계에서의 가장 큰 수 => sum = sum + temp

  sum이 입력한 숫자보다 크거나 같을 때까지 반복문을 돌려 반복 횟수를 출력한다.
*/

#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;

  int temp=0, cnt=1, sum=1;
  while(sum<n) {
    cnt++;
    temp += 6;
    sum += temp;
  }
  cout << cnt;
}