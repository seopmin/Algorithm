#include<iostream>
#include<stack>
using namespace std;
stack<int> st, st1;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  while(n--) {
    string s; cin >> s;
    int dis=0;
    for(int i=0; i<s.size(); i++) {
      if(s[i]=='(')
        st.push(1);
      else {
        if(!st.size()) {
          dis=1;
          break;
        }
        st.pop();
      }
    }
    if(st.size()||dis) {
      cout << "NO" << '\n';
      st = st1;
    } else {
      cout << "YES" << '\n';
    }
  }
}