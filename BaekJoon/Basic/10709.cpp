#include<iostream>
using namespace std;
char map[101][101];
int result[101][101];

int main() {
  int h, w; cin >> h >> w;
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> map[i][j];
      result[i][j] = -1;
    }
  }


  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if(map[i][j]=='c') {
        result[i][j]=0;
        for(int k=j+1; k<w; k++) {
          result[i][k] = result[i][k-1]+1;
        }
      }
    }
  }

  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }
}