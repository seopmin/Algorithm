/*
  단어가 나올 때마다 해당 단어와 매칭된 인덱스의 배열원소 값을 증가시킴
  index 0 : a
  ...
  index 25 : z

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[26];

int main() {
  string s; cin >> s;
  for (int i=0; i<s.size(); i++) {
    a[tolower(s[i])-'a']++;
  }
  int max_e=0; char result; int discern = 0;
  for (int i=0; i<26; i++) {
    if (max_e == a[i]) {
      discern = 1;
      max_e = a[i];
      result = 'a'+i;
    } else if (max_e < a[i]) {
      discern = 0;
      max_e = a[i];
      result = 'a'+i;
    }
  }
  if (discern) cout << '?';
  else printf("%c", toupper(result));
}