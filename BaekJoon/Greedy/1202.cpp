#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, k, M, V, C;
vector<pair<int, int>> nv;
vector<int> kv;
priority_queue<int, vector<int>, less<int>> q;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first<b.first;
}

int main() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> M >> V; nv.push_back({M, V});
	}
	for(int i=0; i<k; i++) {
		cin >> C; kv.push_back(C);
	}

	sort(nv.begin(), nv.end(), comp);
	sort(kv.begin(), kv.end());
	long long result=0;
	for(int i=0, j=0; i<kv.size(); i++) {
		while(j<nv.size() && kv[i]>=nv[j].first) {
			q.push(nv[j].second);
			j++;
		}
		if(q.size()) {
			result += q.top(); q.pop();
		}
	}
	cout << result;
}