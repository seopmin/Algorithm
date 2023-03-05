/*

4 5 5
1 0
5 1
6 1
10 0
17 0  


12 25 8
7 1
25 0
26 0
27 0
28 0
29 0
30 0
31 0

*/

// n: 회전문의 칸 개수
// k: 한번 회전할 때 지속되는 시간(초)
#include<iostream>
#include<vector>
using namespace std;

vector<long long> solve(long long n, long long k, vector<vector<long long>> v) {
  vector<long long> result;
  long long time = v[0][0];
  long long real_k = k;
  int i = 1;
  vector<int> pos;
  pos.push_back(n/2);
  long long last_time = -1;
  int w=0;
  while(time) {
    
    if(last_time == -1) {  // 배열의 잘못된 인덱스 접근을 막기 위해
      if(v[i][0]==time) {
        if(i==v.size()-1) {
          last_time=time+k;
        }
        cout << 1 << endl;
        pos.push_back(n/2);
        i++;

        if(real_k<=0) {
          real_k=k;
        }
      }
    }

    time++;
    real_k--;
    if(real_k >= 0) {
      for(int j=w; j<pos.size(); j++) {
        pos[j]--;
      }
      if(pos.size()!=0 && w < pos.size()) {
        if(pos[w]==0) {
          w++;
          result.push_back(time);
        }
      }
    }
    if(last_time==time) {
      cout << 4 << endl;
      break;
    }    
  }

  for(int i=w; i<pos.size(); i++) {
    result.push_back(-1);
  }

  cout << result.size() << endl;
  return result;
}

int main() {
  long long n, k; cin >> n >> k;
  long long p; cin >> p; // 들어오는 사람의 수(임의)
  vector<vector<long long>> v;
  vector<long long> result;
  for(long long i=0; i<p; i++) {
    vector<long long> v2(2);
    cin >> v2[0] >> v2[1];
    v.push_back(v2);
  }
  result = solve(n, k, v);
  for(int i=0; i<result.size(); i++) {
    cout << result[i] << ' ';
  }
}