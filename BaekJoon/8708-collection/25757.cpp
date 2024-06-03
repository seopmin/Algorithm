/*
  25757.cpp
  임스와 함께하는 미니게임
  - 집합을 통해 같은 원소 제거
  - 플레이할 수 있는 갯수 구함
*/

#include <iostream>
#include <set>
using namespace std;
 
int n; char game;
string s;
set<string> se;
 
int main() {
  cin >> n >> game;
  for(int i=0; i<n; i++) {                                                            
    string s;
    cin >> s;
    se.insert(s);
  }

  if(game == 'Y')  // 두 명 플레이 할 수 있으니(한 명은 임스)
    cout << se.size();
  
  else if(game == 'F')
    cout << se.size()/2;  // 세 명이서 플레이 할 수 있으니(한 명은 임스)
  
  else
    cout << se.size()/3;  // 네 명이서 플레이 할 수 있으니(한 명은 임스)
}