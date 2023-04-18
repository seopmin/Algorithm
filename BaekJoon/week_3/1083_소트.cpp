#include<iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  int v[50];
  for(int i=0; i<n; i++)
    cin >> v[i];

  int s,j,temp; cin >> s;

  for(int i=0; i<n; i++) {
    for(int j=i+s; s!=0 && j>=1; j--) {
      if(j>=n) j=n-1;

      if(v[j] > v[j-1]) {
        int temp=v[j];
        v[j]=v[j-1];
        v[j-1]=temp;
        s--;
      }
    }
  }

  for(int i=0; i<n; i++)
    cout << v[i] << ' ';
}