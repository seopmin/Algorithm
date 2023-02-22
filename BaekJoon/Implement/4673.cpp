#include<iostream>
using namespace std;
int arr[10001];

int func(int k) {
  int sum=0;
  while(k) {
    int temp=k%10;
    sum += temp;
    k /= 10;
  }
  return sum;
}

int main() {
  for(int i=1; i<=10000; i++) {
    int temp = func(i);
    int result = i+temp;
    if(result <=10000) {
      arr[result] = 1; 
    }
  }

  for(int i=1; i<=10000; i++) {
    if(arr[i]) continue;
    cout << i << '\n';
  }
}