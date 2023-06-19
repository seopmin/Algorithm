#include<iostream>
#define MAX 9;
using namespace std;
int N, M, visited[9], arr[9];

void func(int pos, int depth) {
	if(depth == M) {
		for(int i=0; i<M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for(int i=pos+1; i<=N; i++) {
		visited[i]=1;
		arr[depth]=i;
		func(i, depth+1);
		visited[i]=0;
	}
}

int main() {
	cin >> N >> M;
	func(0, 0);
}