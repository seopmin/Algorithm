// Not Solved


/*
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int r, c, n, visited[101][101];
char map[101][101];
vector<pair<int, int>> v;

void init_vector() {
  while(v.size()) {
    v.pop_back();
  }
}

void init_visited() {
  for(int i=1; i<=r; i++) {
    for(int j=1; j<=c; j++) {
      visited[i][j]=0;
    }
  }
}

void print() {
 for(int i=1; i<=r; i++) {
    for(int j=1; j<=c; j++) {
      cout << map[i][j];
    }
    cout << endl;
  }
}

void print_visited() {
  for(int i=1; i<=r; i++) {
    for(int j=1; j<=c; j++) {
      cout << visited[i][j];
    }
    cout << endl;
  }
}

// 클러스터가 분리되어 있을 경우 -> 아래로 떨어짐
void drop() {
  int dis=1, d;
  while(dis){
    for(int i=0; i<v.size(); i++) {
      int x=v[i].first;
      int y=v[i].second;
      if(map[y+1][x]=='x'||y+1>r) {
        dis=0;
        d=i;
        break;
      }
      map[y][x]='.';
      map[y+1][x]='x';
      visited[y+1][x]=1;
      v[i].second++;
    }
  }
  for(int i=d-1; i>=0; i--) {
    int x=v[i].first;
    int y=v[i].second;
    map[y][x]='.';
    visited[y][x]=0;
    map[y-1][x]='x';
  }
}

// 공중에 있는 있는 클러스터 탐색: 백터에 담음
void dfs_split(int x, int y) {
  if(x<1 || y<1 || x>c || y>r) return;
  if(visited[y][x] || map[y][x]!='x') return;
  // cout << "{" << x << ", " << y << "} ";
  v.push_back({x, y});
  visited[y][x]=1;
  dfs_split(x+1, y);
  dfs_split(x-1 ,y);
  dfs_split(x, y+1);
  dfs_split(x, y-1);
}

// 땅에 붙어 있는 클러스터 탐색
void dfs(int x, int y) {
  if(x<1 || y<1 || x>c || y>r) return;
  if(visited[y][x] || map[y][x]!='x') return;
  visited[y][x]=1;
  dfs(x+1, y);
  dfs(x-1 ,y);
  dfs(x, y+1);
  dfs(x, y-1);
}

void discern() {
  int result = false;
  for(int i=r; i>=1; i--) {
    for(int j=c; j>=1; j--) {
      if(!visited[i][j] && map[i][j]=='x') {
        if(i!=r) {
          dfs_split(j, i);
          // cout << "drop" << endl;
          // print();
          drop();
          init_vector();
        } else {
          dfs(j, i);
        }
        
      }
    }
  }
}

// 미네랄 파괴 함수
void destroy(int h, int d) {
  if(d%2) {  // 왼쪽
    // cout << "left" << endl;
    for(int i=1; i<=c; i++) {
      if(map[r-h+1][i]=='x') {
        map[r-h+1][i]='.';
        break;
      }
    }
  } else {
    // cout << "right" << endl;
    for(int i=c; i>=1; i--) {
      if(map[r-h+1][i]=='x') {
        map[r-h+1][i]='.';
        break;
      }
    }
  }
}

int main() {
  cin >> r >> c;
  for(int i=1; i<=r; i++) {
    for(int j=1; j<=c; j++) {
      cin >> map[i][j];
    }
  }

  cin >> n;
  int cnt=0;
  for(int i=0; i<n; i++) {
    int k; cin >> k;
    cnt++;
    destroy(k, cnt);

    discern();
    init_visited();
    // cout << k << endl;
    // print();
    // cout << "---------" << endl;
  }
  print();
}
*/