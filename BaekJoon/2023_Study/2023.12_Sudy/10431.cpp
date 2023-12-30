/*
  줄세우기
  - 둘을 비교했을 때 앞이 더 크면 그중 큰 곳까지 이동하는 거니까, 학생들이 뒤로 이동하는 횟수나 or 이동할 만큼 +1 하는 것과 다르지 않음
  -> 앞과 비교해서 앞이 더 크면 +1 함
*/

#include <iostream>
using namespace std;
int arr[20];

int main() {
  int p, t;
  cin >> p;
  while(p--) {
    int result = 0;
    cin >> t;
    for(int i=0; i<20; i++)
      cin >> arr[i];
    
    for(int i=0; i<20; i++)
      for(int j=i; j<20; j++)
        if(arr[i] > arr[j]) result++;
    
    cout << t << ' ' << result << '\n';
  }
}