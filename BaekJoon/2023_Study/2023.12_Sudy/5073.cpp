/* 
  if문을 만날 때 참이면 continue;

  1. 모두가 0인지 여부 파악
  2. 세 변의 길이가 같을 경우 파악
  3. 정렬
  4. 삼각형이 될 수 없는 경우 파악
  5. 두 변의 길이만 같은 경우 파악
  6. 세 변이 모두 다른 경우
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[3];

int main() {
  while(1) {
    cin >> arr[0] >> arr[1] >> arr[2];

    // 0, 0, 0을 입력했을 경우
    if(!arr[0] && !arr[1] && !arr[2]) break;

    // 세 변의 길이가 같을 경우
    if(arr[0]==arr[1] && arr[0]==arr[2]) { 
      cout << "Equilateral" << '\n';
      continue;
    }
    
    // 정렬
    sort(arr, arr+3);

    // 삼각형이 될 수 없는 경우
    if(arr[2] >= arr[1] + arr[0]) {
      cout << "Invalid" << '\n';
      continue;
    }
    
    // 두 변의 길이만 같은 경우
    if(arr[0]==arr[1] || arr[1]==arr[2] || arr[0]==arr[2]) {
      cout << "Isosceles" << '\n';
      continue;
    }

    // 세 변의 길이가 모두 다른 경우
    cout << "Scalene" << '\n';
  }
}