#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
int n, map[21][21], map2[21][21], res=INT_MAX;

// 경계선을 가지고 1~4구역 구하는 함수
void func(int x, int y, int d1, int d2) {
   // 각 꼭짓점 좌표
    int x0 = x, y0 = y;
    int x1 = x+d1, y1 = y-d1;
    int x2 = x+d1+d2, y2 = y-d1+d2;
    int x3 = x+d2, y3 = y+d2;
 
 
    //모든 선거구를 5로 초기화 하고 시작
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            map2[i][j] = 5;
        }
    }
 
 
    //1번 선거구 설정
    int end = y0;
    for(int i=1; i<x1; i++){
        if(i >= x0) end--;
        for(int j=1; j<=end; j++){
            map2[i][j] = 1;
        }
    }
 
    //2번 선거구 설정
    int start=y0+1;
    for(int i=1; i<=x3; i++){
        if(i > x0) start++;
        for(int j=start; j<=n; j++){
            map2[i][j] = 2;
        }
    }
 
    //3번 선거구 설정
    end = y1-1;
    for(int i=x1; i<=n; i++){
        for(int j=1; j<=end; j++){
            map2[i][j] = 3;
        }
        if(end < y2-1){
            end++;
        }
    }
 
    //4번 선거구 설정
    start = y3;
    for(int i=x3+1; i<=n; i++){
        for(int j=start; j<=n; j++){
            map2[i][j] = 4;
        }
        if(start > y2){
            start--;
        }
    }
 
    return;
}

void func2(int x, int y, int d1, int d2){
   //calculate pop
   int sum[6]={0,0,0,0,0,0};
   for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
         sum[map2[i][j]] += map[i][j];
      }
   }

   sort(sum, sum+6);
   int gap = sum[5]- sum[1];

   res = min(gap, res);
}
 
// 경계선 결정하는 함수
void boundary(int x, int y) {
   for(int d1=1; d1<=n; d1++) {
      for(int d2=1; d2<=n; d2++) {
         if(x+d1+d2 <= n && y+d2<=n && y-d1>=1) {
            func(x,y,d1,d2);
            func2(x,y,d1,d2);      
         }
      }
   }
}

int main() {
   cin >> n;
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         cin >> map[i][j];
      }
   }
   
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         boundary(i, j);
      }
   }
   cout << res;
}