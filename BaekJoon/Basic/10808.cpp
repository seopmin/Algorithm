#include<iostream>
using namespace std;
int alph[26]={0,};

int main() {
  string s; cin >> s;
  for(char a : s) {
    alph[a-'a']++;
  }
  for(int i=0; i<26; i++) {
    cout << alph[i] << ' ';
  }
}
