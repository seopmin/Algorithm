
#include<iostream>
using namespace std;
int N, M, a[9];

void func(int pos, int depth) {
  if(M==depth) {
    for(int i=0; i<M; i++)
      cout << a[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i=pos; i<=N; i++) {
    a[depth]=i;
    func(i, depth+1);
  }
}

int main() {
  cin >> N >> M;
  func(1, 0);
}
