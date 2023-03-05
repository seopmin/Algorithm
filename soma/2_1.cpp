#include<iostream>
#include<string>
#include<vector>
#include<tuple>
using namespace std;


vector<vector<int>> solve(string s) {
  vector<vector<int>> result;
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='>') {
      int cnt=0;
      int temp=1;
      for(int j=i-1; j>=0; j--) {
        if(s[j]=='<') {
          temp=0;
          break;
        }
        if(s[j]=='>') {
          break;
        }
        cnt++;
      }
      vector<int> v;
      v.push_back(temp);
      v.push_back(cnt);
      result.push_back(v);
    }
  
    if(s[i]=='<') {
      int cnt=0;
      int temp=-1;
      int discern=0;
      for(int j=i+1; j<s.size(); j++) {
        if(s[j]=='<') {
          break;
        }
        if(s[j]=='>') {
          discern=1;
          break;
        }
        cnt++;
      }
      if(!discern) {
        vector<int> v;
        v.push_back(temp);
        v.push_back(cnt);
        result.push_back(v);
      }
    }
  }
  return result;

}

int main() {
  string s; cin >> s;
  vector<vector<int>> v;
  v = solve(s);
  for(int i=0; v.size(); i++) {
    cout << v[i][0] << ' ' << v[i][1] << endl;
  }
}