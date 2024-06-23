#include <iostream>
#include <queue>
#include <functional> 
#include <tuple>
#include <vector>
#include <string.h>
using namespace std;

int n, m, x;
vector<pair<int, int>> v[1001];
int dest[1001];
int result;

void dkstra(int start, int end) {
    memset(dest, 987654321, sizeof(dest));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dest[start] = 0;

    while(pq.size()) {
        int crnt, c_dst;
        tie(crnt, c_dst) = pq.top(); pq.pop();
        if (crnt == end) {
            result = dest[crnt];
            return;
        }
        for (int i=0; i<v[crnt].size(); i++) {
            int nxt = v[crnt][i].first;
            int n_dst = v[crnt][i].second + c_dst;
            if (dest[nxt] > n_dst) {
                dest[nxt] = n_dst;
                pq.push({n_dst, nxt});
            }
        }

    }
}

int main() {
    int ans1, ans2, ans;
    ans = 0;
    cin >> n >> m >> x;
    for (int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for (int i = 1; i <= n;i++){
        dkstra(i, x);
        ans1 = result; 
        dkstra(x, i);
        ans2 = result;
        if(ans < ans1+ans2) {
            ans = ans1 + ans2;
        }
    }
    cout << ans << '\n';
}