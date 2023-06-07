#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, k, visited[101], a[101], cnt;
vector<int> v;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i=0; i<k; i++) cin >> a[i];
	for(int i=0; i<k; i++) {
		if(!visited[a[i]]) {
			if(v.size()==n) {
				int last_idx=0, pos;
				for(int e : v) {
					int here_pick = INT_MAX;
					for(int j=i+1; j<k; j++)
						if(e==a[j]) { here_pick=j; break; }
					
					if(last_idx<here_pick) {
						last_idx=here_pick;
						pos = e;
					}
				}
				visited[pos]=0;
				cnt++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(a[i]); visited[a[i]]=1;
		}
	}
	cout << cnt;
}