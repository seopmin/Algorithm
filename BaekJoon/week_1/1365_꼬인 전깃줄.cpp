// LIS 구하는 문제
#include<iostream>
#include<vector>
using namespace std;
int arr[1000001];  // 값을 삽입할 배열
vector<int> result;
int len, input; // len: arr에서 탐색할 길이를 나타내는 배열, input: 둘째 줄에 입력될 값들

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n; cin >> n;
  for(int i=0; i<n; i++) {
    cin >> input;
    auto pos = lower_bound(arr, arr+len, input);  // lower_bound 위치 반환
    if(*pos == 0) len++;  // 탐색할 길이 증가
    *pos=input;  // 값 업데이트
  }

  cout << n-len << '\n';
}