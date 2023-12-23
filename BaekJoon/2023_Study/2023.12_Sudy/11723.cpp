/*
  [11723 - 집합]
  <배열 사용>
  1. 숫자의 범위 가 1부터 20까지이니 이에 맞는 배열(arr) 선언
  2. n이라는 숫자를 추가할 때는 arr[n] = 1;
  3. 뺄 때는 arr[n] = 0;
  4. 확인할 때는 arr[n]을 출력
*/

#include <iostream>
#include <string.h>
int arr[21];

int main() {
  std::ios_base::sync_with_stdio(false); 
  std::cin.tie(NULL); 
  std::cout.tie(NULL);
  std::string s;
  int k, n;
  std::cin >> k;
  
  while(k--) {
    std::cin >> s;
    if (s == "add") {
      std::cin >> n;
      arr[n] = 1;
    } else if (s == "remove") {
      std::cin >> n;
      arr[n] = 0;
    } else if (s == "check") {
      std::cin >> n;
      std::cout << arr[n] << '\n';
    } else if (s == "toggle") {
      std::cin >> n;
      arr[n] = !arr[n];
    } else if (s == "all") {
      for(int i=0; i<21; i++)
        arr[i] = 1;
      // memset(arr, 1, sizeof(int)*21);   <- 1은 초기화 안됨 memset이 1바이트 단위로 초기화 함
    } else {
      memset(arr, 0, 84);  // 4(int 바이트) x 21(배열의 수) = 84
    }
  }
}