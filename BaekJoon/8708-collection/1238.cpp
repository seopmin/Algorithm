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
    memset(dest, 98765432, sizeof(dest));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dest[start] = 0;

    while(pq.size()) {
        int crnt = pq.top().second; // 현재 정점
        int c_dst = pq.top().first;  // 현재 정점까지의 거리
        pq.pop();

        if (crnt == end) {
            result = dest[crnt];
            break;
        }

        for (int i=0; i<v[crnt].size(); i++) {
            int nxt = v[crnt][i].first;  // 다음 정점
            int n_dst = v[crnt][i].second + c_dst; // 다음정점까지의 거리 계산
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