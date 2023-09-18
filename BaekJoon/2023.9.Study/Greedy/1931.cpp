#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int , int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);  // 끝나는 시간을 기준으로 오름차순
    
    int count = 1; int last = v[0].second;
    for(int i=1; i<n; i++){
        if(v[i].first >= last){
            count++;
            last = v[i].second;
        }
    }

    cout << count;    
}