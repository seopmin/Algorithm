#include<iostream>
using namespace  std;

int count1 = 1;
int count2 = 0;
int visited[10000];

int fib(int n){
  if(visited[n]==1) {
    return visited[n];
  }
  if(n==1 || n==2) return 1;
  visited[n] = fib(n-1) + fib(n-2)
  count1++;
  return visited[n];
}

int fibonacci(int n){
  int f[40] = {1, 1,};
  for(int i=2; i<n; i++){
    f[i] = f[i-1] + f[i-2];
    count2++;
  }
  return f[n-1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  fib(n);
  fibonacci(n);

  cout << count1 << ' ' << count2;
}