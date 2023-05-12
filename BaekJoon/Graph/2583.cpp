#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int m, n, k, map[101][101], visited[101][101], area;
vector<int> v;

void dfs(int y, int x) {
  if(visited[y][x] || map[y][x]) return;
  if(x<0 || y<0 || x>=n || y>=m) return;
  visited[y][x] = 1;
  area++;
  dfs(y+1, x);
  dfs(y-1, x);
  dfs(y, x+1);
  dfs(y, x-1);
}

int main() {
  cin >> m >> n >> k;
  for(int i=0; i<k; i++) {
    int l_x, l_y, r_x, r_y;
    cin >> l_x >> l_y >> r_x >> r_y;

    for(int i=l_y; i<r_y; i++) {
      for(int j=l_x; j<r_x; j++) {
        map[i][j]=1;
      }
    }
  }
  int cnt=0;
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      if(!visited[i][j] && !map[i][j]) {
        area=0;
        dfs(i, j);
        v.push_back(area);
        cnt++;
      }
    }
  }
  sort(v.begin(), v.end());
  cout << cnt << endl;
  for(int i=0; i<v.size(); i++) {
    cout << v[i] << ' ';
  }
}