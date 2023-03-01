#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
  vector<int> v(6);
  for(int i=0; i<6; i++) {
    v[i] = i;
  }

  // vector 에서의 find -> 내장 함수

  auto it = find(v.begin(), v.end(), 3);
  if(it == v.end()) {
    cout << "값이 없음" << endl;
  } else {
    cout << "해당 인덱스 : " << it-v.begin() << endl;
  }


  // string 에서 find string 클래스에 선언돼 있는 메서드
  string s = "134125";
  if(s.find("1") == string::npos) {
    cout << "값이 없음" << endl;
  } else {
    cout << s.find("1",1) << endl;
  }

}