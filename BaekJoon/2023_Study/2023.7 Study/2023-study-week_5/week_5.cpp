/* 15686 치킨 배달 */
// 1. 치킨 거리가 가장 작은 M개의 치킨집을 골라 벡터에 거리 정보만 저장
/*
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<cstdlib>
#include<limits.h>
using namespace std;
int n, m, h_x, h_y, c_x, c_y, map[51][51], select_c[14], result=INT_MAX;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int func() {
  int sum=0;
  for(int i=0; i<home.size(); i++) {
    tie(h_x, h_y) = home[i];
    int distance=INT_MAX;
    for(int j=0; j<14; j++) {
      if(select_c[j] == 1) {
        tie(c_x, c_y) = chicken[j];
        distance = min(distance, abs(h_x-c_x)+abs(h_y-c_y));
      }
    }
    sum += distance;
  }
  return sum;
}

void combi(int cnt, int k) {
  if(cnt==m) {  // m만큼 치킨집을 뽑음
    result = min(result,func());  // 가장 최적의 치킨 거리를 찾음
    return;
  }

  for(int i=k+1; i<chicken.size(); i++) {
    select_c[i]=1;
    combi(cnt+1, i);
    select_c[i]=0;
  }
}

int main() {
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
      if(map[i][j]==1) home.push_back({j, i});
      else if(map[i][j]==2) chicken.push_back({j, i});
    }
  }
  
  for(int i=0; i<chicken.size(); i++) {
    select_c[i]=1;
    combi(1, i);
    select_c[i]=0;
  }
  cout << result;
}
*/

// 큐빙 5373
/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//  U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면
// 초기 큐브 세팅
// 윗면: w, 아랫면: y, 앞 면, r, 뒷 면: o, 왼쪽 면: g, 오른쪽 면: b
int tc, n;
string s;
char basic_cube[6][3][3] = {
	{{'w','w','w'},{'w','w','w'},{'w','w','w'}},
	{{'y','y','y'},{'y','y','y'},{'y','y','y'}},
	{{'o','o','o'},{'o','o','o'},{'o','o','o'}},
	{{'r','r','r'},{'r','r','r'},{'r','r','r'}},
	{{'g','g','g'},{'g','g','g'},{'g','g','g'}},
	{{'b','b','b'},{'b','b','b'},{'b','b','b'}}
};

char cube[6][3][3];

// 사이드에 붙어있는 큐브 세팅
void setting_2(int pos, int dir) {
	char t1, t2, t3;
	if(pos==0) {
		if(dir==1) {
			t1=cube[2][0][0], t2 = cube[2][0][1], t3=cube[2][0][2];
			cube[2][0][0]=cube[4][0][0], cube[2][0][1]=cube[4][0][1], cube[2][0][2]=cube[4][0][2];
			cube[4][0][0]=cube[3][0][0], cube[4][0][1]=cube[3][0][1], cube[4][0][2]=cube[3][0][2];
			cube[3][0][0]=cube[5][0][0], cube[3][0][1]=cube[5][0][1], cube[3][0][2]=cube[5][0][2];
			cube[5][0][0]=t1, cube[5][0][1]=t2, cube[5][0][2]=t3;
		} else {
			t1 = cube[2][0][0], t2 = cube[2][0][1], t3 = cube[2][0][2];
			cube[2][0][0]=cube[5][0][0], cube[2][0][1]=cube[5][0][1], cube[2][0][2]=cube[5][0][2];
			cube[5][0][0] = cube[3][0][0], cube[5][0][1] = cube[3][0][1], cube[5][0][2] = cube[3][0][2];
			cube[3][0][0] = cube[4][0][0], cube[3][0][1] = cube[4][0][1], cube[3][0][2] = cube[4][0][2];
			cube[4][0][0] = t1, cube[4][0][1] = t2, cube[4][0][2] = t3;
		}
	} else if(pos==1) {
		if(dir==1) {
			t1 = cube[2][2][0], t2 = cube[2][2][1], t3 = cube[2][2][2];
			cube[2][2][0] = cube[5][2][0], cube[2][2][1] = cube[5][2][1], cube[2][2][2] = cube[5][2][2];
			cube[5][2][0] = cube[3][2][0], cube[5][2][1] = cube[3][2][1], cube[5][2][2] = cube[3][2][2];
			cube[3][2][0] = cube[4][2][0], cube[3][2][1] = cube[4][2][1], cube[3][2][2] = cube[4][2][2];
			cube[4][2][0] = t1, cube[4][2][1] = t2, cube[4][2][2] = t3;
		} else {
			t1 = cube[2][2][0], t2 = cube[2][2][1], t3 = cube[2][2][2];
			cube[2][2][0] = cube[4][2][0], cube[2][2][1] = cube[4][2][1], cube[2][2][2] = cube[4][2][2];
			cube[4][2][0] = cube[3][2][0], cube[4][2][1] = cube[3][2][1], cube[4][2][2] = cube[3][2][2];
			cube[3][2][0] = cube[5][2][0], cube[3][2][1] = cube[5][2][1], cube[3][2][2] = cube[5][2][2];
			cube[5][2][0] = t1, cube[5][2][1] = t2, cube[5][2][2] = t3;
		}
	} else if(pos==2) {
		if(dir==1) {
			t1=cube[0][0][2], t2=cube[0][0][1], t3=cube[0][0][0];
			cube[0][0][2]=cube[5][2][2], cube[0][0][1]=cube[5][1][2], cube[0][0][0]=cube[5][0][2];
			cube[5][2][2]=cube[1][2][2], cube[5][1][2]=cube[1][2][1], cube[5][0][2]=cube[1][2][0];
			cube[1][2][2]=cube[4][0][0], cube[1][2][1]=cube[4][1][0], cube[1][2][0]=cube[4][2][0];
			cube[4][0][0]=t1, cube[4][1][0]=t2, cube[4][2][0]=t3;
		} else {
			t1=cube[0][0][2], t2=cube[0][0][1], t3=cube[0][0][0];
			cube[0][0][2]=cube[4][0][0], cube[0][0][1]=cube[4][1][0], cube[0][0][0]=cube[4][2][0];
			cube[4][0][0]=cube[1][2][2], cube[4][1][0]=cube[1][2][1], cube[4][2][0]=cube[1][2][0];
			cube[1][2][2]=cube[5][2][2], cube[1][2][1]=cube[5][1][2], cube[1][2][0]=cube[5][0][2];
			cube[5][2][2]=t1, cube[5][1][2]=t2, cube[5][0][2]=t3;
		}
	} else if(pos==3) {
		if(dir==1) {
			t1=cube[0][2][2], t2=cube[0][2][1], t3=cube[0][2][0];
			cube[0][2][2]=cube[4][0][2], cube[0][2][1]=cube[4][1][2], cube[0][2][0]=cube[4][2][2];
			cube[4][0][2]=cube[1][0][2], cube[4][1][2]=cube[1][0][1], cube[4][2][2]=cube[1][0][0];
			cube[1][0][2]=cube[5][2][0], cube[1][0][1]=cube[5][1][0], cube[1][0][0]=cube[5][0][0];
			cube[5][2][0]=t1, cube[5][1][0]=t2, cube[5][0][0]=t3;
		} else {
			t1=cube[0][2][2], t2=cube[0][2][1], t3=cube[0][2][0];
			cube[0][2][2]=cube[5][2][0], cube[0][2][1]=cube[5][1][0], cube[0][2][0]=cube[5][0][0];
			cube[5][2][0]=cube[1][0][2], cube[5][1][0]=cube[1][0][1], cube[5][0][0]=cube[1][0][0];
			cube[1][0][2]=cube[4][0][2], cube[1][0][1]=cube[4][1][2], cube[1][0][0]=cube[4][2][2];
			cube[4][0][2]=t1, cube[4][1][2]=t2, cube[4][2][2]=t3;
		}
	} else if(pos==4) {
		if(dir==1) {
			t1=cube[0][2][0], t2=cube[0][1][0], t3=cube[0][0][0];
			cube[0][2][0]=cube[2][0][2], cube[0][1][0]=cube[2][1][2], cube[0][0][0]=cube[2][2][2];
			cube[2][0][2]=cube[1][2][2], cube[2][1][2]=cube[1][1][2], cube[2][2][2]=cube[1][0][2];
			cube[1][2][2]=cube[3][2][0], cube[1][1][2]=cube[3][1][0], cube[1][0][2]=cube[3][0][0];
			cube[3][2][0]=t1, cube[3][1][0]=t2, cube[3][0][0]=t3;
		} else {
			t1=cube[0][2][0], t2=cube[0][1][0], t3=cube[0][0][0];
			cube[0][2][0]=cube[3][2][0], cube[0][1][0]=cube[3][1][0], cube[0][0][0]=cube[3][0][0];
			cube[3][2][0]=cube[1][2][2], cube[3][1][0]=cube[1][1][2], cube[3][0][0]=cube[1][0][2];
			cube[1][2][2]=cube[2][0][2], cube[1][1][2]=cube[2][1][2], cube[1][0][2]=cube[2][2][2];
			cube[2][0][2]=t1, cube[2][1][2]=t2, cube[2][2][2]=t3;
		}
	} else if(pos==5) {
		if(dir==1) {
			t1=cube[0][2][2], t2=cube[0][1][2], t3=cube[0][0][2];
			cube[0][2][2]=cube[3][2][2], cube[0][1][2]=cube[3][1][2], cube[0][0][2]=cube[3][0][2];
			cube[3][2][2]=cube[1][2][0], cube[3][1][2]=cube[1][1][0], cube[3][0][2]=cube[1][0][0];
			cube[1][2][0]=cube[2][0][0], cube[1][1][0]=cube[2][1][0], cube[1][0][0]=cube[2][2][0];
			cube[2][0][0]=t1, cube[2][1][0]=t2, cube[2][2][0]=t3;
		} else {
			t1=cube[0][2][2], t2=cube[0][1][2], t3=cube[0][0][2];
			cube[0][2][2]=cube[2][0][0], cube[0][1][2]=cube[2][1][0], cube[0][0][2]=cube[2][2][0];
			cube[2][0][0]=cube[1][2][0], cube[2][1][0]=cube[1][1][0], cube[2][2][0]=cube[1][0][0];
			cube[1][2][0]=cube[3][2][2], cube[1][1][0]=cube[3][1][2], cube[1][0][0]=cube[3][0][2];
			cube[3][2][2]=t1, cube[3][1][2]=t2, cube[3][0][2]=t3;
		}
	}
}

// pos: cube에 돌릴 면의 index 위치, dir: 방향 1(오른쪽) -1(왼쪽)
void setting_1(int pos, int dir) {
  if(pos==1) dir=dir*-1;

	if(dir==1) {  //오른쪽으로 회전
		for(int i=0; i<3; i++) {
			for(int j=i; j<3; j++) {
				swap(cube[pos][i][j], cube[pos][j][i]);
			}
		}
		for(int i=0; i<3; i++) {
			for(int j=0; j<3/2; j++) {
				swap(cube[pos][i][j], cube[pos][i][3-j-1]);
			}
		}
	} else if(dir==-1) {  // 왼쪽으로 회전
		for(int i=0; i<3; i++) {
			for(int j=i; j<3; j++) {
				swap(cube[pos][i][j], cube[pos][j][i]);
			}
		}
		for(int j=0; j<3; j++) {
			for(int i=0; i<3/2; i++) {
				swap(cube[pos][i][j], cube[pos][3-i-1][j]);
			}
		}
	}
  if(pos==1) dir=dir*-1;
	setting_2(pos, dir);
}

void init_cube() {
	for(int i=0; i<6; i++) {
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) {
				cube[i][j][k] = basic_cube[i][j][k];
			}
		}
	}
}

int main() {
	cin >> tc;
	while(tc--) {
		cin >> n;
		init_cube();
		for(int i=0; i<n; i++) {
			cin >> s;
			int pos;
			if(s[0]=='U')
				pos=0;
			else if(s[0]=='D')
				pos=1;
		  else if(s[0]=='F')
				pos=3;
			else if(s[0]=='B')
				pos=2;
			else if(s[0]=='L')
				pos=4;
			else if(s[0]=='R')
				pos=5;
			
			if(s[1]=='+') setting_1(pos, 1);
			else setting_1(pos, -1);
		}
    
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				cout << cube[0][i][j];
      }
			cout << endl;
    }
	}
}
*/

/*
1
7
D+ L- B- U+ D+ B+ B+
*/
/*
yyb
wwg
wwg
*/



/* 16234 인구이동 */
/*
// 알아야 할 것: 칸의 개수, 국경선 열린 칸의 총 합을 알아서 갱신되는 값 구함.
// 저장: 값을 갱신해야할 좌표들을 모음.
// 그 이후에 해야할 것 -> 값 세팅

#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std;
int n, l, r, sum, map[51][51], visited[51][51], room_cnt;
vector<pair<int, int>> v;

// DFS 함수: 인구 이동이 가능한 칸들을 탐색
void dfs(int x, int y, int prev_x, int prev_y, int discern) {
  if(x<0 || y<0 || x>=n || y>=n || visited[y][x]) return;
  int k=abs(map[y][x]-map[prev_y][prev_x]);
  if((k>=l && k<=r) || discern) {   // discern: dfs의 깊이 첫번째만 통과시키려고
    visited[y][x]=1;
    sum+=map[y][x]; // 연합의 총 인구수
    room_cnt++;
    v.push_back({x, y});
    dfs(x+1, y, x, y, 0);
    dfs(x-1, y, x, y, 0);
    dfs(x, y+1, x, y, 0);
    dfs(x, y-1, x, y, 0);
  }
}

// 설정 함수: 연합된 칸들의 인구를 재설정
void setting(int val) {
  int x, y;
  for(int i=0; i<v.size(); i++) {
    tie(x, y) = v[i];
    map[y][x] = val;
  }
}

// 인구 이동 가능한지 검사하고, 가능하다면 인구 이동 실행
int solve() {
  int dis=0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(!visited[i][j]) {
        sum=0; room_cnt=0;
        dfs(j, i, j, i, 1);
        if(room_cnt==1) dis++;
        else setting(sum/room_cnt);  // 연합된 칸들의 인구 재설정
        v.clear();
      }
    }
  }
  if(dis==n*n) return 1;  // 더이상 인구 이동이 없는 경우
  return 0;
}

int main() {
  cin >> n >> l >> r;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
    }
  }
  int cnt=0;
  while(1) {
    if(solve()) { cout << cnt; break; }
    memset(visited, 0, sizeof(visited));
    cnt++;
  }
}
*/


/* 16235 나무 재테크 */
// 봄: 나무-나이먹음(나이만큼 양분을 먹지 못하면 죽음)
// 여름: 봄에 죽은 나무가 양분으로 변함(나무 나이/2만큼 양분 추가)
// 가을: 나무 번식(인접한 8방향의 칸)
// 겨울: 양분 추가
/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int n, m, k, a[11][11], res;
int dy[]={-1, -1, 0, 1, 1, 1, 0, -1};
int dx[]={0, 1, 1, 1, 0, -1, -1, -1};
typedef struct info {
  int nutrient;
  deque<int> tree;
}info;

vector<deque<info>> v;


void spring_summer() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      int size = v[i][j].tree.size();
      int dead_pos=size;
      int &s2d2 = v[i][j].nutrient;
      for(int w=0; w<size; w++) {
        if(s2d2-v[i][j].tree[w] >= 0) {
          s2d2 -= v[i][j].tree[w];  // 양분의 나이만큼 땅 양분 감소
          v[i][j].tree[w]++;
        } else {
          dead_pos=w;
          break;
        }
      }
      for(int w=dead_pos; w<size; w++)
        s2d2 += v[i][j].tree[w]/2;  // (죽은 나무의 나이 / 2) -> 땅 양분에 추가
      
      for(int w=dead_pos; w<size; w++)
        v[i][j].tree.pop_back();  // 죽은 나무 cut

    }
  }
}

void fall_winter() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      v[i][j].nutrient += a[i][j];  // 양분 추가(겨율)
      int size = v[i][j].tree.size();
      for(int w=0; w<size; w++) {  // 나무 번식(가을)
        if(v[i][j].tree[w]%5) continue;
        for(int u=0; u<8; u++) {
          int nx=j+dx[u];
          int ny=i+dy[u];
          if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
          v[ny][nx].tree.push_front(1);
          // v[ny][nx].tree.push_back(1);
          // sort(v[ny][nx].tree.begin(), v[ny][nx].tree.end());
        }
      }
    }
  }
}

int main() {
  cin >> n >> m >> k;
  for(int i=0; i<n; i++) {
    deque<info> temp;
    for(int j=0; j<n; j++) { 
      cin >> a[j][i];
      info w;
      w.nutrient=5;   // 해당 위치의 양분 5로 초기화
      temp.push_back(w);
    }
    v.push_back(temp);
  }

  for(int i=0; i<m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    v[y-1][x-1].tree.push_back(z);
    sort(v[y-1][x-1].tree.begin(), v[y-1][x-1].tree.end());
  }

  while(k--) {
    // 봄, 여름
    spring_summer();
    
    // 가을, 겨울
    fall_winter();
  }
  
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      res += v[i][j].tree.size();
    }
  }
  cout << res;
}
*/