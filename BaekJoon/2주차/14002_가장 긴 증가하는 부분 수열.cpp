#include<iostream>
#include<vector>
using namespace std;
int arr[1000001];
vector<int> result;
int len, input;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n; cin >> n;
  vector<pair<int, int>> v;
  for(int i=0; i<n; i++) {
    cin >> input;
    auto pos = lower_bound(arr, arr+len, input);
    int len_index = (int)(pos - arr);
    if(*pos == 0) len++;
    *pos=input;
    v.push_back({input, len_index});
  }

  cout << len << '\n';
  for(int i=v.size()-1; i>=0; i--)
    if(v[i].second == len-1) {
      result.push_back(v[i].first); len--;
    }

  for(int i=result.size()-1; i>=0; i--) {
    cout << result[i] << ' ';
  }
}