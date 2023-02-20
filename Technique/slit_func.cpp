// 문자열을 어떠한 기준으로 쪼개어서 배열에 담고 싶을 때 사용하는 함수
// cpp에서는 지원을 하지 않아서 직접 구현해야 함

#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<string> split(string input, string delimiter) {
  vector<string> ret;
  long long pos = 0;
  string token = "";
  while((pos = input.find(delimiter)) != string::npos) {
    token = input.substr(0, pos);
    ret.push_back(token);
    input.erase(0, pos+delimiter.length());
  }
  ret.push_back(input);
  return ret;
}

int main() {
  string s = "첫번째 두번째", d=" ";
  vector<string> a = split(s, d);
  for(string b : a) cout << b << "\n";
}
