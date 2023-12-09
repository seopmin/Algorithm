#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());  // 인출시간을 기준으로 오름차순 정렬
    int sum=0; int result = 0;
    for(int i=0; i<n; i++){
        sum += v[i];
        result += sum;
    }
    cout << result;
}