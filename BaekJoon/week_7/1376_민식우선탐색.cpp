#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> node[100001];
int visited[100001];
int node_count[10001];
int n, e, a, b;

void mfs(int k, int depth) {
  if(depth==n) return;
  if(visited[k])return;
  if(node_count[k]==0) return;
  
  visited[k]=1;
  cout << k << ' ';
  if(node_count[k]%2==0) {
    int temp = node[k][0];
    node[k].erase(node[k].begin());
    node_count[k]--;
    mfs(temp, depth+1);
  } else {
    int mid = node_count[k]/2;
    int temp = node[k][mid];
    node[k].erase(node[k].begin()+mid);
    node_count[k]--;
    mfs(temp, depth+1);
  }
  visited[k]=0;
}


int main() {
  cin >> n >> e;
  for(int i=0; i<e; i++) {
    cin >> a >> b;
    node[a].push_back(b);
    node[b].push_back(a);
    node_count[a]++;
    node_count[b]++;
  }

  for(int i=1; i<=n; i++)
    sort(node[i].begin(), node[i].end());
  
  mfs(1, 0);
}