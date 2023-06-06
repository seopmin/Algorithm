#include<iostream>
#include<vector>
using namespace std;
int s, e, res;
vector<int> v;

int main() {
  int n; cin >> n;
  vector<int> ch(n+1,1);

  for(int i=2; i*i<=n; i++) {
    if(ch[i]==0) continue;
    for(int j=i+i; j<=n; j+=i) {
      ch[j]=0;
    }
  }

  for(int i=2; i<=n; i++)
    if(ch[i]) v.push_back(i);

  while(e<v.size()) {
    int temp=0;
    for(int i=s; i<=e; i++) {
      temp += v[i];
    }

    if(temp<n) {
      e++;
    } else if(temp>n) {
      s++;
    } else {
      res++;
      e++;
    }
  }
  cout << res;
}
