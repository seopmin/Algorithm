#include <iostream>
#include <deque>

using namespace std;

int n, input, size;
deque<pair<int, int>> dq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; std::cin >> n;
    bool is_res = false;
    for (int i=1; i<=n; i++) {
        cin >> input;
        while (dq.size() != 0 && dq.back().first < input) {
            // 필요 없는 원소들은 제거
            dq.pop_back();
        }
        if (dq.size() == 0)
            printf("%d ", 0);
        else
            printf("%d ", dq.back().second);

        dq.push_back({input, i});
    }
}