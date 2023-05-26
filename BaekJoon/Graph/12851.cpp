#include<iostream>
#include<queue>
#include<tuple>
#include<limits.h>
using namespace std;
int n, k, sec, visited[100001];
int result_sec=INT_MAX, cnt=1;
queue<pair<int, int>> q;

void func(int pos, int sec) {
  // 방문은 했지만, 초가 같으면 q에 푸쉬
  if(pos>=0 && pos<=100000 && (!visited[pos]||sec==visited[pos])) { visited[pos]=sec; q.push({pos, sec+1}); }
}

void bfs(int pos) {
  q.push({pos, 0});
  visited[pos]=1;

  while(q.size()) {
    tie(pos, sec) = q.front(); q.pop();
    if(sec > result_sec) return;
    if(pos==k && sec==result_sec) { cnt++; }
    else if(pos==k) { result_sec=sec; }
    for(int next : {pos+1, pos-1, pos*2}) func(next, sec);
  }
}

int main() {
  cin >> n >> k;
  bfs(n);
  cout << result_sec << '\n' << cnt;
}