#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
string s1, temp, s2 = "123456780";
set<string> visited;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int depth, x, y, zero, nx, ny;

int bfs() {
  queue<pair<string, int>> q;
  q.push({s1, 0});
  visited.insert(s1);
  while(!q.empty()) {
    tie(s1, depth) = q.front(); q.pop();
    if(s1 == s2)  return depth;

    zero = s1.find('0');
    x = zero/3; y = zero%3;
    for(int i=0; i<4; i++) {
      nx = x+dx[i];
      ny = y+dy[i];
      if (nx < 0 || ny < 0 || nx > 2 || ny > 2) continue;
      
      temp = s1;
      swap(temp[x*3+y], temp[nx*3+ny]);
      if(visited.find(temp) == visited.end()){
        visited.insert(temp);
        q.push({temp, depth+1});
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for(int i=0; i<9; i++) {
    cin >> temp;
    s1 += temp;
  }
  cout << bfs();
}


// dfs 탐색으로는 실패... 뭔가 계속 실행됨. 반복은 아닌 것 같은데 경우의 수가 너무 많아서 그런가
// #include<iostream>
// #include<vector>
// #include<limits.h>
// #include<stdlib.h>
// using namespace std;
// int result=INT_MAX;
// string s2="123456780";
// vector<string> visited;
// int count_e =0;
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};



// void dfs(int x, int y, int depth, string s1){
//   count_e++;
//   if (count_e == 100) {
//     exit(1);
//   }
//   if(x<0 || y<0 || x>2 || y>2)
//     return;
//   if(s1==s2){
//     result=min(result,depth);
//     return;
//   }
//   if(find(visited.begin(), visited.end(), s1) != visited.end()){
//     cout << "called" <<endl;
//     return;
//   }
  


//   cout << depth << " : " << s1 << endl;
//   cout << '[';
//   for(int i=0; i<visited.size(); i++) {
//     cout << visited[i] << ' ';
//   }
//   cout << ']'<< endl;
//   visited.push_back(s1);
//   for(int i=0; i<4; i++) {
//     int nx = x+dx[i]; int ny = y+dy[i];
//     swap(s1[nx*3+ny], s1[x*3+y]);
//     dfs(nx, ny, depth+1, s1);
//     swap(s1[nx*3+ny], s1[x*3+y]);
//   }
// }

// int main() {
//   string s1, temp;
//   for(int i=0; i<9; i++) {
//     cin >> temp;
//     s1 += temp;
//   }
  
//   int zero = s1.find('0');
//   int x = zero/3;
//   int y = zero%3;
//   dfs(x, y, 0, s1);
//   cout << result;
// }