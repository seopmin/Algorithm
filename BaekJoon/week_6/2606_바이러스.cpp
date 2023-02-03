#include<iostream>
#include<vector>
using namespace std;
int n, m, a, b, result=0;
vector<int> network[101];
int visitied[101]={0};

void dfs(int depth) {
  for(int i=0; i<network[depth].size(); i++) {
    visitied[depth]=1;
    if(!visitied[network[depth][i]]) {
      dfs(network[depth][i]);
      result+=1;
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    network[a].push_back(b);
    network[b].push_back(a);
  }

  dfs(1);
  cout << result;
}