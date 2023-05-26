#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int n,k,pos,cnt, visited[100001], result;
queue<pair<int,int>> q;
vector<int> v;

void bfs() {
  q.push({n,0});
  visited[n]=1;
  while(q.size()) {
    tie(pos,cnt) = q.front(); q.pop();
    // cout << "pos: " << pos << ", cnt: " << cnt << endl;
    int arr[] = {0,pos-1,pos+1,pos*2};
    for(int i=1; i<=3; i++) {
      if(arr[i]>=0 && arr[i]<100001 && !visited[arr[i]]) {
        visited[arr[i]]=i;
        if(arr[i]==k) {
          result=cnt+1;
          return;
        }
        q.push({arr[i],cnt+1});
      }
    }
  }
}

int main() {
  cin >> n >> k;
  bfs();

  
  int pos=k;
  v.push_back(k);
  for(int i=0; i<result; i++) {
    if(visited[pos]==1)
      pos += 1;
    else if(visited[pos]==2)
      pos -= 1;
    else if(visited[pos]==3) pos /= 2;
    v.push_back(pos);
  }
  cout << result << '\n';
  for(int i=result; i>=0; i--) {
    cout << v[i] << ' ';
  }
}