#include<iostream>
#include<queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n;
  priority_queue<int, vector<int>, less<int>> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;

  for(int i=0; i<n; i++) {
    cin >> k;
    if(max_heap.size() == min_heap.size()) {
      max_heap.push(k);
    } else if(max_heap.size() < min_heap.size()) {
      max_heap.push(k);
    } else {
      min_heap.push(k);
    }
    
    if(!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
      int a=max_heap.top(); max_heap.pop();
      int b=min_heap.top(); min_heap.pop();
      max_heap.push(b);
      min_heap.push(a);
    }
    cout << max_heap.top() << '\n';
  }
}