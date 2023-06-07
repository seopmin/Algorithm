#include<iostream>
#include<algorithm>
using namespace std;
int n, x, s, e, a[100001], res;

int main() {
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	cin >> x;
	sort(a, a+n);
	e = n-1;
	while(s<e) {
		if(a[s]+a[e]<x)
			s++;
		else if(a[s]+a[e]>x)
			e--;
		else { res++; s++; }
	}
	cout << res;
}