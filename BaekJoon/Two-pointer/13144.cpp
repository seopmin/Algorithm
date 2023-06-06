#include<iostream>
using namespace std;
int n, s, e, arr[100001], cnt[100001];
long long res;

int main() {
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	while(e<n) {
		if(!cnt[arr[e]]) {
			cnt[arr[e]]++;
			e++;
		} else {
			cnt[arr[s]]--;
			res += (e-s);
			s++;
		}
	}
	res += (long long)(e-s)*(e-s+1)/2;
	cout << res;
}