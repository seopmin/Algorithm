#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    vector<int> v(N);
    for(int i=0; i<N; i++)
        cin >> v[i];

    int count=0;
    for(int i=N-1; i>=0; i--){  // 가장 마지막 인덱스(가치가 큰 수)부터 접근
        int n=K/v[i];
        if(n!=0){
            count += n;
            K -= n*v[i];
        }
    }
    cout << count;
}