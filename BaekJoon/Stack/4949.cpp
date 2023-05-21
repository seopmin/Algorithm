#include<iostream>
#include<stack>
using namespace std;

string str;
int main() {
  while(1) {
    stack<int> st;
    getline(cin, str);
    if(str==".") break;

    for(int i=0; i<str.size(); i++) {
      if(str[i] == '(') st.push(1);
      else if(str[i] == '[') st.push(2);
      else if(str[i] == ')') {
        if(st.size() && st.top()==1) st.pop();
        else { cout << "no\n"; break; }
      }
      else if(str[i] == ']') {
        if(st.size() && st.top()==2) st.pop();
        else { cout << "no\n"; break; }
      }
      if(!st.size() && i==str.size()-1) cout << "yes\n";
      else if(st.size() && i==str.size()-1) cout << "no\n";
    }
  }
}