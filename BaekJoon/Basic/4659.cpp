#include<iostream>
#include<string>
using namespace std;
string mo = "aeiou";

int main() {
  string s;
  cin >> s;
  while(s!="end") {
    char prev=' ';
    int dis_1=0, dis=1, mo_cnt=0, ja_cnt=0;
    for(char c : s) {
      if(mo.find(c) != string::npos) dis_1=1, mo_cnt++, ja_cnt=0;
      else mo_cnt=0, ja_cnt++;

      if(mo_cnt==3 || ja_cnt==3) dis=0;
      if(prev==c && prev!='e' && prev!='o') dis=0;
      prev=c;
    }
    if(dis_1 && dis)
      cout << "<" << s << ">" << " is acceptable." << endl; 
    else 
      cout << "<" << s << ">" << " is not acceptable." << endl;  
    cin >> s; 
  }
}