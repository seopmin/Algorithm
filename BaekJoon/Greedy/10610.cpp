#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool comp(char a, char b) {
  return a > b;
}

string solved(string s) {
  if(s[s.size()-1] != '0') {
    return "-1";
  } else {
    int sum=0;
    for(int i=0; i<s.size(); i++) {
      sum += s[i]-'0';
    }
    if(sum % 3 == 0) {
      return s;
    }
  }
  return "-1";
  
}

int main() {
  string s; cin >> s;
  sort(s.begin(), s.end(), comp);
  cout << solved(s);
}