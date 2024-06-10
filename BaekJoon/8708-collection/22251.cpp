#include <iostream>

using namespace std;

int n, k, p, x;

int arr[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 숫자 0
  {0, 1, 1, 0, 0, 0, 0},  // 숫자 1
  {1, 1, 0, 1, 1, 0, 1},  // 숫자 2
  {1, 1, 1, 1, 0, 0, 1},  // 숫자 3
  {0, 1, 1, 0, 0, 1, 1},  // 숫자 4
  {1, 0, 1, 1, 0, 1, 1},  // 숫자 5
  {1, 0, 1, 1, 1, 1, 1},  // 숫자 6
  {1, 1, 1, 0, 0, 0, 0},  // 숫자 7
  {1, 1, 1, 1, 1, 1, 1},  // 숫자 8
  {1, 1, 1, 1, 0, 1, 1}   // 숫자 9
};

int main() {
  cin >> n >> k >> p >> x;

  int result=0;
  for (int i=1; i<=n; i++) {
    if (i==x) continue;  // x와 같을 경우 반전이 없기 때문에 continue;
    int cnt = 0;
    int start = x, end = i;

    for (int j=0; j<k; j++) {  // 디스플레이의 수만큼 반복
      for (int z=0; z<7; z++) {  // 각 숫자를 비교하여 반전해야하는 LED 수를 카운트 함
        if (arr[start%10][z]!=arr[end%10][z]) cnt++;
      }
      start /= 10;
      end /= 10;
    }
    if (cnt <= p) result++; 
  }
  cout << result;
}