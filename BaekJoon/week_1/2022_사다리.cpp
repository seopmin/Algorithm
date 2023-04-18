#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double x, y, c, comp;

// 닮음비를 이용해서 식 도출 함수 -> 변수 c와 비교를 함으로써 이진탐색을 할 것임
// 유의할 점! -> 무한반복!!
double solve(double k) {
  double hx = sqrt(x*x - k*k);
  double hy = sqrt(y*y - k*k);
  return (hx*hy)/(hx+hy);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> x >> y >> c;
  double mid, left=0, right=min(x, y);
  while(left+1e-6<right) {
    mid = (left+right)/2.0;
    comp = solve(mid);  // comp 변수에 함수값 할당!
    if (c == comp) break;
    else if(c < comp)  // comp가 더 크다는 것은 -> 즉, 두 빌딩 거리가 구하고자 하는 k보다 더 작다는 것이기 때문에 left 값을 바꾸어줌
      left = mid;
    else
      right = mid;
  }
  cout << mid << endl;
}