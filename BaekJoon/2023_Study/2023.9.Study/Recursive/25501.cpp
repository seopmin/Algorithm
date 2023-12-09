#include<iostream>
#include<string.h>
using namespace std;
int cnt;

int recursion(char *s, int l, int r) {
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(char* s) {
	return recursion(s, 0, strlen(s)-1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	char s[1002];
	for(int i=0; i<n; i++) {
		cin >> s;
		cnt = 0;
		cout << isPalindrome(s) << ' ' << cnt << '\n';
	}
}