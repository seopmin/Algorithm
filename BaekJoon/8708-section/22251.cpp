#include <iostream>

using namespace std;

int n, k, p, x;

// typedef struct {
//   int m_arr[7];
// } number;

// number v[10];

int g_arr[10][7];

bool checkArr(int a[], int b[], int size) {
  for (int i=0; i<size; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

void dfs(int arr[], int depth) {
  
  if (depth > p) return;

  
  for (int i=0; i<=n; i++) {

  }
}

int main() {
  cin >> n >> k >> p >> x;

  g_arr[0] = {1, 1, 1, 1, 1, 1, 0};  // 숫자 0
  g_arr[1] = {0, 1, 1, 0, 0, 0, 0};  // 숫자 1
  g_arr[2] = {1, 1, 0, 1, 1, 0, 1};  // 숫자 2
  g_arr[3] = {1, 1, 1, 1, 0, 0, 1};  // 숫자 3
  g_arr[4] = {0, 1, 1, 0, 0, 1, 1};  // 숫자 4
  g_arr[5] = {1, 0, 1, 1, 0, 1, 1};  // 숫자 5
  g_arr[6] = {1, 0, 1, 1, 1, 1, 1};  // 숫자 6
  g_arr[7] = {1, 1, 1, 0, 0, 1, 0};  // 숫자 7
  g_arr[8] = {1, 1, 1, 1, 1, 1, 1};  // 숫자 8
  g_arr[9] = {1, 1, 1, 1, 0, 1, 1};  // 숫자 9

}