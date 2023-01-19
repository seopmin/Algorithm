#include<iostream>
#include<vector>
using namespace std;
int arr[1000001];  // 값을 삽입할 배열
vector<int> result;
int len, input;  // len: arr에서 탐색할 길이를 나타내는 배열, input: 둘째 줄에 입력될 값들

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n; cin >> n;
  vector<pair<int, int>> v;
  for(int i=0; i<n; i++) {
    cin >> input;
    auto pos = lower_bound(arr, arr+len, input);  // lower_bound 위치 반환
    int len_index = (int)(pos - arr);  // arr주소값을 빼므로 위치를 인덱스로 반환
    if(*pos == 0) len++;  // 탐색할 길이 증가
    *pos=input;  // 값 업데이트
    v.push_back({input, len_index});
  }

  cout << len << '\n';
  for(int i=v.size()-1; i>=0; i--)
    if(v[i].second == len-1) {
      result.push_back(v[i].first); len--;
    }

  for(int i=result.size()-1; i>=0; i--) {
    cout << result[i] << ' ';
  }
}