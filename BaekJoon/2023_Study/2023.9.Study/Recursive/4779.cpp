#include<iostream>
#include<cmath>
using namespace std;

void func(int n) {
	if (n == 0) {
		cout << '-';
		return;
	}
	func(n - 1);
	for(int i=0; i<pow(3, n-1); i++) {
		cout << ' ';
	}
	func(n - 1);
}

int main() {
	int n;
	while (cin >> n) {
		func(n);
		cout << '\n';
	}
}