#include<iostream>
#include<queue>
#include<tuple>
#include<limits.h>
using namespace std;
int n, arr[3], a, b, c, d, result=INT_MAX;
int dp[61][61][61];
queue<tuple<int, int, int, int>> q;

void func(int op[], int cnt) {
  if(op[0]<=0 && op[1]<=0 && op[2]<=0) { result = min(result,cnt); return; }
  if(op[0]<0) op[0]=0;
  if(op[1]<0) op[1]=0;
  if(op[2]<0) op[2]=0;
  if(dp[op[0]][op[1]][op[2]]) return;
  dp[op[0]][op[1]][op[2]] = cnt;
  q.push({op[0], op[1], op[2], cnt});
}

void bfs() {
  q.push({arr[0], arr[1], arr[2], 0});
  while(q.size()) {
    tie(a,b,c,d) = q.front(); q.pop();
    if(++d>=result) return;
    int op1[]={a-9,b-3,c-1}, op2[]={a-9,b-1,c-3}, op3[]={a-3,b-9,c-1}, op4[]={a-3,b-1,c-9}, op5[]={a-1,b-9,c-3}, op6[]={a-1,b-3,c-9};
    func(op1,d); func(op2,d); func(op3,d); func(op4,d); func(op5,d); func(op6,d);
  }
}

int main() {
  cin >> n;
  while(n--) cin >> arr[n];

  bfs();
  cout << result;
}