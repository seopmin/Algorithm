#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[500001];

int main() {
  int n, k; cin >> n;
  for(int i=1; i<=n; i++)
    cin >> arr[i];
  
  sort(arr, arr+n+1);
  
  long long res=0;
  for(int i=1; i<=n; i++)
    res += abs(arr[i]-i);

  cout << res;
}