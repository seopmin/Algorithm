/*
  7568번 덩치
  1. 본인보다 덩치가 큰 사람이 있으면 ranking을 증가시켜 매 for문 마다 출력 시킴.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<pair<int, int>> v(n);
  for(int i=0; i<n; i++)
    cin >> v[i].first >> v[i].second;

  for(int i=0; i<n; i++){
    int ranking=1;  
    for(int j=0; j<n; j++){
      if(v[i].first<v[j].first && v[i].second<v[j].second)
        ranking++;  // 자기보다 덩치가 큰 사람 있으면 -> +1
    }
    cout << ranking << ' ';
  }
}