#include<iostream>
#include<vector>
using namespace std;
int result=-1, temp;
vector<vector<int>> pre_arr;
vector<int> v(9);

int check2() {

}

int check(int (*arr)[3]) {
  int compare=1;
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      if(arr[i][j]!=compare++) return 0;
  
  return 1;
}

void dfs(int pre_x, int pre_y, int now_x, int now_y, int depth, int (*arr)[3]){
  if(now_x<0 || now_y<0 || now_x>2 || now_y>2)
    return;
  if(check(arr)){
    result=depth;
    return;
  }

  
  

  temp=arr[pre_y][pre_x];
  arr[pre_y][pre_x]=arr[now_y][now_x];
  arr[now_y][now_x]=temp;

  dfs(now_x, now_y, now_x+1, now_y, depth+1, arr);
  dfs(now_x, now_y, now_x-1, now_y, depth+1, arr);
  dfs(now_x, now_y, now_x, now_y+1, depth+1, arr);
  dfs(now_x, now_y, now_x, now_y-1, depth+1, arr);
}

int main() {
  int arr[3][3], a, b;
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++){
      cin >> arr[i][j];
      if(arr[i][j]==0) {
        a=j; b=i;
      }
    }

  dfs(a,b,a,b,0, arr);
  cout << result;
}