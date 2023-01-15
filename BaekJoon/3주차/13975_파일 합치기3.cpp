#include<iostream>
#include<queue>
using namespace std;
int n, f, input;
long long result, temp;


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> f;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for(int j=0; j<f; j++){
      cin >> input;
      q.push(input);
    }

    result=0;
    while(q.size()!=1){
      temp = q.top();
      q.pop();
      temp += q.top();
      q.pop();
      q.push(temp);
      result += temp;
    }

    cout << result << endl;
  }
}