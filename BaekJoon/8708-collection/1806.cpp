#include <iostream>
using namespace std;

int n, s, front, back;
int result = 987654321;
int arr[100001];
int cur_val;
int cur_cnt;

int main() {
  cin >> n >> s;
  for (int i=0; i<n; i++) {
    cin >> arr[i];
  }

  cur_val = arr[0];
  cur_cnt = 1;

  if (cur_val >= s) result = min(result, cur_cnt);
  
  front = 1;
  while (front <= n) {
    cur_val += arr[front];
    cur_cnt += 1;

    while (back <= front) {
      if (cur_val - arr[back] < s) break;
      cur_val -= arr[back];
      back++;
      cur_cnt--;
    }

    // cout << cur_val << " ";
    if (cur_val >= s) {
      result = min(result, cur_cnt);
    }
    front++;
  }

  // cout << endl;
  if (result == 987654321) {
    cout << 0;
  } else {
    cout << result;
  }

}