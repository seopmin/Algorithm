#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;
vector<string> result;

bool comp(string a, string b) {
  if(a.size() == b.size()) return a<b;
  return a.size() < b.size();
}
int main() {
  int n; cin >> n;
  while(n--) {
    string s; cin >> s;
    v.push_back(s);
  }
  for(int i=0; i<v.size(); i++) {
    string s = v[i];
    
    for(int j=0; j<s.size(); j++) {
      int dis=0;
      string num = "";
      while(s[j]>='0' && s[j]<='9' && j<s.size()) {;
        num+=s[j];
        dis=1;
        if(num.size()>1 && num[0]=='0') {
          num=s[j];
        }
        j++;
      }
      if(dis) result.push_back(num);
    }
  }

  sort(result.begin(), result.end(), comp);
  for(int i=0; i<result.size(); i++)
    cout << result[i] << endl;
}