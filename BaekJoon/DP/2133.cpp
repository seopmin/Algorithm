#include<iostream>
using namespace std;
int n, DP[31]={0,3}, A[31]={0,1}, B[31]={1,0};
int main() {
  cin >> n;
  for(int i=2; i<n; i++) {
    //A[i]=B[i-1];
    //B[i]=DP[i-1]+A[i-1];
    A[i]=DP[i-2]+A[i-2];
    DP[i]=DP[i-2]+2*A[i];
  }
  
  cout << DP[n-1];
}