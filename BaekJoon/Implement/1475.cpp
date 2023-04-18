#include<iostream>
using namespace std;
int arr[9];

int solved(int n) {
  while(n) {
    int temp=n%10;
    if(temp==9 || temp==6) {
      arr[6]++;
    } else {
      arr[temp]++;
    }
    n /= 10;
  }
  if(arr[6]%2==0) {
    arr[6] /= 2;
  } else {
    arr[6] /= 2;
    arr[6]++;
  }
  int result=0;
  for(int i=0; i<9; i++) {
    if(result<arr[i]) {
      result = arr[i];
    }
  }
  return result;
}

int main() {
  int n; cin >> n;
  cout << solved(n);
}