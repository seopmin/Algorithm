// 봄: 나무-나이먹음(나이만큼 양분을 먹지 못하면 죽음)
// 여름: 봄에 죽은 나무가 양분으로 변함(나무 나이/2만큼 양분 추가)
// 가을: 나무 번식(인접한 8방향의 칸)
// 겨울: 양분 추가

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
      int size=v[i][j].tree.size();
      int dead_pos=size;
      int &yangbun=v[i][j].nutrient;
      for(int w=0; w<size; w++) {
        if(yangbun-v[i][j].tree[w] >= 0) {
          yangbun -= v[i][j].tree[w];  // 양분의 나이만큼 땅 양분 감소
          v[i][j].tree[w]++;
        } else {
          dead_pos=w;
          break;
        }
      }
      for(int w=dead_pos; w<size; w++)
        yangbun += v[i][j].tree[w]/2;  // (죽은 나무의 나이 / 2) -> 땅 양분에 추가
      
      for(int w=dead_pos; w<size; w++)
        v[i][j].tree.pop_back();  // 죽은 나무 컷

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