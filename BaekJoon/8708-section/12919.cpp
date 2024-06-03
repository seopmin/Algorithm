// A와 B 2
#include <iostream>
#include <algorithm>
using namespace std;
std::string S, T;


// bool appendA(std::string);
// bool appendBAndReverse(std::string);


// bool appendA(std::string s) {
//   if (s == T) return true;
//   if (s.length() >= T.length()) return false; 
//   s = s+"A";
//   return appendA(s) || appendBAndReverse(s);
// }

// bool appendBAndReverse(std::string s) {
//   if (s == T) return true;
//   if (s.length() >= T.length()) return false; 
//   s = s + "B";
//   reverse(s.begin(), s.end());
//   return appendA(s) || appendBAndReverse(s);
// }

bool func(std::string t) {
  if (S==t) return true;
  if (S.length() >= t.length()) return false;
  
  bool return_v=false;

  if (t[t.size()-1]=='A') {
    std::string k = t;
    k.erase(k.begin()+k.size()-1);
    return_v = return_v || func(k);
  }
  if (t[0]=='B') {
    std::string k = t;
    k.erase(k.begin());
    reverse(k.begin(), k.end());
    return_v = return_v || func(k);
  }
  return return_v;
}

int main() {
  cin >> S;
  cin >> T;

  printf("%d", func(T));
  // printf("%d", appendA(S) || appendBAndReverse(S));
}