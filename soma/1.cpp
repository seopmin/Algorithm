#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<limits.h>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int n;
int result=INT_MAX;
set<string> mem;

// 같은면 반환 1, 다르면 반환 0
int check(vector<string> v) {
  for(int i=0; i<v.size(); i++) {
    if(v[i][0]!=v[i][1]) return 0;
  }
  return 1;
}

string change(vector<string> v) {
  string s;
  for(int i=0; i<v.size(); i++) {
    s += v[i];
  }
  return s;
}

void bfs(vector<string> v) {
  queue<pair<vector<string>, int>> q;
  q.push({v, 0});
  

  while(q.size()) {
    int depth;
    cout << "depth: " << depth << endl;
    vector<string> v;
    tie(v, depth)=q.front(); q.pop();

    if(check(v)) {
      result = min(result, depth);
      continue;
    }
    string s = change(v);
    if(mem.find(s) != mem.end()) {
      continue;
    }
    mem.insert(s);

    // 왼 왼
    swap(v[0][0], v[1][0]);
    q.push({v, depth+1});
    swap(v[0][0], v[1][0]);
    // 오 오
    swap(v[0][1], v[1][1]);
    q.push({v, depth+1});
    swap(v[0][1], v[1][1]);
    // 왼 오
    swap(v[0][0], v[1][1]);
    q.push({v, depth+1});
    swap(v[0][0], v[1][1]);
    
    swap(v[0][1], v[1][0]);
    q.push({v, depth+1});
    swap(v[0][1], v[1][0]);

    for(int i=1; i<v.size()-1; i++) {
      swap(v[i][0], v[i+1][0]);
      q.push({v, depth+1});
      swap(v[i][0], v[i+1][0]);
      // 오 오
      swap(v[i][1], v[i+1][1]);
      q.push({v, depth+1});
      swap(v[i][1], v[i+1][1]);
      // 왼 오
      swap(v[i][0], v[i+1][1]);
      q.push({v, depth+1});
      swap(v[i][0], v[i+1][1]);

      swap(v[i][1], v[i+1][0]);
      q.push({v, depth+1});
      swap(v[i][1], v[i+1][0]);
    }
  }
}

// void dfs(vector<string> v, int depth) {
//   cout << "depth: " << depth << endl;
//   if(check(v)) {
//     result = min(result, depth);
//     return;
//   }

//   string s = change(v);
//   if(mem.find(s) != mem.end()) {
//     return;
//   }
//   mem.insert(s);
  
//   // 왼 왼
//   swap(v[0][0], v[1][0]);
//   dfs(v, depth+1);
//   swap(v[0][0], v[1][0]);
//   // 오 오
//   swap(v[0][1], v[1][1]);
//   dfs(v, depth+1);
//   swap(v[0][1], v[1][1]);
//   // 왼 오
//   swap(v[0][0], v[1][1]);
//   dfs(v, depth+1);
//   swap(v[0][0], v[1][1]);
  
//   swap(v[0][1], v[1][0]);
//   dfs(v, depth+1);
//   swap(v[0][1], v[1][0]);

//   for(int i=1; i<v.size()-1; i++) {
//     swap(v[i][0], v[i+1][0]);
//     dfs(v, depth+1);
//     swap(v[i][0], v[i+1][0]);
//     // 오 오
//     swap(v[i][1], v[i+1][1]);
//     dfs(v, depth+1);
//     swap(v[i][1], v[i+1][1]);
//     // 왼 오
//     swap(v[i][0], v[i+1][1]);
//     dfs(v, depth+1);
//     swap(v[i][0], v[i+1][1]);

//     swap(v[i][1], v[i+1][0]);
//     dfs(v, depth+1);
//     swap(v[i][1], v[i+1][0]);
//   }
// }

int solved(int k, vector<string> v) {
  n = k;
  bfs(v);
  // dfs(v, 0);
  return result;
}

int main() {
  int n; cin >> n;
  string s;
  vector<string> v;
  for(int i=0; i<n; i++) {
    cin >> s;
    v.push_back(s);
  }
  cout << solved(n, v);
}