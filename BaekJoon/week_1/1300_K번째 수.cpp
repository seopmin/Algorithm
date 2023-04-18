// k번째 수를 m이라고 했을 때
// m미만인 수는 k보다 작고
// m이하의 수는 k보다 크거나 같다.
#include<iostream>
#include<cmath>
using namespace std;
long long n, k;

typedef struct {
  long long less_equal_cnt = 0; 
  long long less_than_cnt = 0;
} Index;

Index solve(long long m) {
  Index index;
  for(int i=1; i<n+1; i++) {
    if(n*i < m){
      index.less_equal_cnt += n;
      index.less_than_cnt += n;
    } else {
      long long w = m / i;
      index.less_equal_cnt += w;
      if(m%i)
        index.less_than_cnt += w;
      else
        index.less_than_cnt += w-1;
    }
  }
  return index;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n; cin >> k; 

  long long left = 1, right = n*n, mid;
  while(left <= right) {
    mid = (left+right) / 2;
    Index index = solve(mid);
    if(index.less_equal_cnt < k) {
      left = mid+1;
    } else if(index.less_than_cnt >= k) {
      right = mid-1;
    } else{
      break;
    }
  }
  cout << mid << endl;
}
