#include<iostream>
#include<queue>
#include<tuple>
#include<string.h>
using namespace std;
int r, c, n, b, pos, x, y, visited[101][101], min_discern;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
char m[101][101];
bool disc;
vector<pair<int, int>> v;

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[b][a]=1;
	while(q.size()) {
		tie(x,y) = q.front(); q.pop();
		for(int i=0; i<4; i++) {
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<0 || ny<0 || nx>=c || ny>=r) continue;
			if(!visited[ny][nx] && m[ny][nx]=='x') {
				visited[ny][nx]=1;
				q.push({nx, ny});
			}
		}
	}
}

void distroy(bool disc, int b) {
	pos = r-b;
	if(disc) {
		for(int i=0; i<c; i++)
			if(m[pos][i]=='x') { m[pos][i]='.'; return; }
	} else {
		for(int i=c-1; i>=0; i--)
			if(m[pos][i]=='x') { m[pos][i]='.'; return; }
	}
}

void bfs2(int a, int b, int cnt) {
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[b][a]=cnt;
	while(q.size()) {
		tie(x,y) = q.front(); q.pop();
		int discern=r-y;
		for(int i=y+1; i<r; i++) {
			if(visited[i][x]==1) {
				discern=i-y;
				break;
			}
		}
		min_discern = min(min_discern, discern);
		for(int i=0; i<4; i++) {
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<0 || ny<0 || nx>=c || ny>=r) continue;
			if(!visited[ny][nx] && m[ny][nx]=='x') {
				visited[ny][nx]=cnt;
				q.push({nx, ny});
			}
		}
	}
}

void setting(int cnt) {
	for(int i=r-2; i>=0; i--) {
		for(int j=0; j<c; j++) {
			if(visited[i][j]==cnt) {
				visited[i][j]=0;
				visited[i+min_discern][j]=cnt;
				m[i][j]='.';
				m[i+min_discern][j]='x';
			}
		}
	}
}

void floating() {
	int cnt=2;
	for(int i=r-1; i>=0; i--) {
		for(int j=0; j<c; j++) {
			if(!visited[i][j] && m[i][j]=='x') {
				min_discern=101;
				bfs2(j, i, cnt);
				min_discern--;
				setting(cnt);
				cnt++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			cin >> m[i][j];

	cin >> n;
	for(int i=0; i<n; i++) {
		memset(visited, 0, sizeof(visited));
		cin >> b;
		disc = !disc;
		distroy(disc, b);
		for(int i=0; i<c; i++) {
			if(m[r-1][i]=='x' && !visited[r-1][i]) bfs(i, r-1);
		}
		floating();
	}
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++)
			cout << m[i][j];
		cout << endl;
	}
}

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