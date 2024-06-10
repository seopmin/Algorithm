#include <iostream>
using namespace std;

int n, s, front, back;
int result = 987654321;
int arr[100001];
int dp[100001];
int cur_val;

int main() {
  cin >> n >> s;
  for (int i=0; i<n; i++) {
    cin >> arr[i];
  }

  if (arr[0] <= s) {
    cur_val = arr[0];
    dp[0] = 1;
    if (cur_val >= s) {
      result = min(result, dp[front]);
    }
  }
  front = 1;

  while (front <= n) {
    cur_val += arr[front];
    dp[front] = dp[front-1] + 1;

    while (back <= front) {
      if (cur_val - arr[back] < s) break;
      cur_val -= arr[back];
      back++;
      dp[front]--;
    }

    // cout << cur_val << " ";
    if (cur_val >= s) {
      result = min(result, dp[front]);
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