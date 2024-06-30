#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n, a, b, max_val;

int main() {
    deque<int> d;
    cin >> n >> a >> b;
    max_val = max(a, b);

    d.push_back(max_val);
    
    for (int i=a-1; i>0; i--) {
        d.push_front(i);
    }

    for (int i=b-1; i>0; i--) {
        d.push_back(i);
    }

    if (d.size() > n) {
        cout << -1;
        return 0;
    }

    int first = d.front();
    d.pop_front();

    int size = d.size();
    for (int i=1; i<=n-size-1; i++) {
        d.push_front(1);
    }

    d.push_front(first);

    for (int i=0; i<d.size(); i++) {
        cout << d[i] << ' ';
    }
}