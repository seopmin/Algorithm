#include<iostream>
#include<algorithm>
using namespace std;
int N, sum, A[51], B[51];

bool comp(int a, int b) {
  return a>b;
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> A[i];
  for(int i=0; i<N; i++)
    cin >> B[i];

  sort(A, A+N);
  sort(B, B+N, comp);

  for(int i=0; i<N; i++)
    sum += A[i]*B[i];

  cout << sum;
}