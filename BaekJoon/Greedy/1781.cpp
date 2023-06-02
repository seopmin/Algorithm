#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
priority_queue<int, vector<int>, less<int>> q;
vector<pair<int, int>> v;

bool comp(pair<int, int> a, pair<int, int> b) {
  return a.first>b.first;
}

int main() {
  int n; cin >> n;
  for(int i=0; i<n; i++) {
    int a,b; cin >> a >> b;
    v.push_back({a,b});
  }
  sort(v.begin(), v.end(), comp);

  long long sum=0;
  for (int i=n,j=0;i>0;i--) {
		while (j < n && i == v[j].first) {
			// cout << "푸시: " << v[j].second << "\n";
			q.push(v[j].second);
			j++;
		}
    if(q.empty()) continue;
    sum += q.top();
    q.pop();
	}
  cout << sum;
}