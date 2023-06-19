#include<iostream>
using namespace std;
int N, M, arr[8];

void func(int depth) {
	if(depth == M) {
		for(int i=0; i<M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for(int i=1; i<=N; i++) {
		arr[depth]=i;
		func(depth+1);
	}
}

int main() {
	cin >> N >> M;
	func(0);	
}