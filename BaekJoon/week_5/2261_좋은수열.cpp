#include<iostream>
#include<string>
using namespace std;
int n, discern = 0;

int compare(string s) {
  int l = s.size()-1;
  int j=1;
  for(int i=1; i<=l; i+=2) {
    string s1 = s.substr(l-i, j);
    string s2 = s.substr(l-j+1, j);
    j++;
    if(s1==s2) return 1;
  }
  return 0;
}

void dfs(int depth, string s) {
  if(discern) return;
  if(compare(s)) return;
  if(depth==n) {
    cout << s;
    discern = 1;
    return;
  }

  dfs(depth+1, s+"1");
  dfs(depth+1, s+"2");
  dfs(depth+1, s+"3");
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  dfs(0, "");
}













// #include<iostream>
// #include<vector>
// using namespace std;
// int n; vector<int> result;

// // 동일한 부분 수열이 있으면 return 1; 없으면 return 0;
// int compare(int index) {
//   bool dis = true;
//   for(int i=0; i<n; i++) {
//     cout << result[i];
//   }
//   cout << endl;
//   for(int i=1; i<=index; i+=2) {
//     int mid = (index+index-i)/2;
//     for(int j=0; j<=i/2; j++)
//       if(result[index-i+j] == result[mid+1+j]) dis = false;
    
//     if(dis==false) return 1;
//   }
  
//   return 0;
// }

// int dfs(int depth, int num) {
//   if(depth >= n)
//     return 0;
  
//   cout << "depth :  " << depth << " / num : " << num << endl;

//   result[depth] = num;
//   if(compare(depth)){
//     if(depth==0) goto Point;
//     // result[depth] = -1;
//     return 0;
//   }
//   Point:
//   cout << "-------------- " << endl;
//   for(int i=1; i<=3; i++) {
//     if(dfs(depth+1, i)) return 1;
//   }

//   cout << "exit depth :  " << depth << " / num : " << num << endl;
//   return 1;
// }

// int main() {
//   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//   cin >> n;
//   for(int i=0; i<n; i++) {
//     result.push_back(0);
//   }
//   for(int i=1; i<=3; i++) {
//     if(dfs(0, i)) break;
//   }
//   for(int i=0; i<n; i++) {
//     cout << result[i];
//   }
//   // cout << 1;

// }