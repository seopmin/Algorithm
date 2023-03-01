#include<iostream>
#include<queue>
#include<tuple>
#include<string.h>
#include<vector>
using namespace std;
string map[101];
int key[26];
int n, w, h, cnt;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0}; 
int visited[101][101];


void init() {
  memset(visited, 0, sizeof(visited));
  memset(key, 0, sizeof(key));
  cnt=0;
}

// key 초기화 함수
void bfs() {
  queue<pair<int, int>> q;
  queue<pair<int, int>> door_pos[26];
  for(int i=0; i<w; i++) {
    if(map[h-1][i]=='.') q.push({i, h-1});
    if(map[0][i]=='.') q.push({i, 0});
  }
  for(int i=0; i<h; i++) {
    if(map[i][w-1]=='.') q.push({w-1, i});
    if(map[i][0]=='.') q.push({0, i});
  }
  // cout << q.size() << endl;

  while(q.size()) {
    int x, y; tie(x,y)=q.front(); q.pop();

    for(int i=0; i<4; i++) {
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx>=0 && ny>=0 && nx<w && ny<h) {
        
        if(visited[ny][nx]) continue;
        visited[ny][nx]=1;
        char pos=map[ny][nx];
        if(pos=='*') continue;
        if(pos>='A' && pos<='Z') {
          if(!key[pos-'A']) {
            door_pos[pos-'A'].push({nx, ny});
            continue;
          } else {
            map[ny][nx]='.';
          }
        }
        if(pos>='a' && pos<='z') {
          key[pos-'a']=1;
          while(door_pos[pos-'a'].size()) {
            q.push(door_pos[pos-'a'].front());
            door_pos[pos-'a'].pop();
          }
    
          // cout << pos-'a' << endl;
          map[ny][nx]='.';
          memset(visited, 0, sizeof(visited));
        }
        if(pos=='$') {
          map[ny][nx]='.';
          // cout << "nx: " << nx << ", ny: " << ny << endl;
          // cout << pos << endl;
          cnt++;
        }
        // cout << "nx: " << nx << ", ny: " << ny << endl;
        
        q.push({nx, ny});
      }
    }

    
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i=0; i<n; i++) {
    
    init();
    cin >> h >> w;
    for(int j=0; j<h; j++) {
      cin >> map[j];
    }
    // cout << map[1][0] << endl;
    string k; cin >> k;
    if(k!="0") {
      for(int j=0; j<k.size(); j++) {
        key[k[j]-'a']=1;
      }
    }
    bfs();
    cout << cnt << '\n';
  }
}


// 열쇠를 획득하면 방문기록 초기화
// #include<iostream>
// #include<tuple>
// using namespace std;
// string map[101];
// int key[26], doors[26];
// int n, m, cnt;
// int visited[101][101];
// pair<int, int> door[26];

// void func(){
//   //key 메모리 초기화
//   memset(visited, 0, sizeof(visited));
//   for(int j=0; j<26; j++) {
//       key[j]=0;
//       doors[j]=0;
//   }
// }

// void dfs(int x, int y) {
//   if(x>=0 && y>=0 && x<m && y<n) {
//     if(map[y][x]=='*') return;
//     if(visited[y][x]==1) return;
//     if(map[y][x]<='Z' && map[y][x]>='A') {
//       map[y][x]='.';
//       door[map[y][x]-'A']={x, y};
//       doors[map[y][x]-'A']=1;
//       return;
//     } else if(map[y][x]<='z' && map[y][x]>='a') {
//       key[map[y][x]-'a']=1;
//       map[y][x]='.';
//     } else if(map[y][x]=='$') {
//       map[y][x]='.';
//       cnt++;
//     }
//     visited[y][x]=1;
//     dfs(x+1, y);
//     dfs(x-1, y);
//     dfs(x, y+1);
//     dfs(x, y-1);
//     visited[y][x]=0;
//   }
// }

// int main() {
//   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int l; cin >> l;
//   string k;
//   for(int i=0; i<l; i++) {
//     cin >> n >> m;
//     for(int j=0; j<n; j++) 
//       cin >> map[j];

    
//     cin >> k;
//     for(int j=0; j<k.size(); j++) {
//       key[k[j]-'a']=1;
//     }

//     cnt=0;
//     for(int j=0; j<m; j++) {
//       if(map[0][j]=='.') dfs(j, 0);
//       if(map[n-1][j]=='.') dfs(j, 0);
//     }
//     for(int j=0; j<n; j++) {
//       if(map[j][0]=='.') dfs(0, j);
//       if(map[j][m-1]=='.') dfs(m-1, j);
//     }

//     for(int j=0; j<26; j++) {
//       if(key[j] && doors[j]) {
//         int x,y; tie(x,y)=door[j];
//         dfs(x, y);
//       }
//     }
//     func();
//     cout << cnt << '\n';
//   }
// }