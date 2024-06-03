#include <iostream>
#include <set>
#include <tuple>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
int n, cnt;
string s1, s2, temp;
int result = INT_MAX;

void turnOver(int idx) {
    if (idx>0) temp[idx-1] = (temp[idx-1]=='0') ? '1' : '0';
    temp[idx] = (temp[idx]=='0') ? '1' : '0';
    if (idx<n-1) temp[idx+1] = (temp[idx+1]=='0') ? '1' : '0';\
}

void func(int k) {
    temp = s1; 
    cnt = 0;
    if (k == 0) {
        temp[0] = (temp[0]=='0') ? '1' : '0';
        temp[1] = (temp[1]=='0') ? '1' : '0';
        cnt++;
    }
    cout << endl;
    for (int i=1; i<n; i++) {
        if (temp[i-1] != s2[i-1]) {
            turnOver(i);
            cnt++;
            
            cout << temp << ' ' << s2 << ' ' << cnt << endl;
        }
    }
   
    if(temp == s2) result = min(result, cnt);
}

int main() {
    cin >> n;
    cin >> s1 >> s2;

    func(0);
    func(1);

    if (result == INT_MAX) {
        cout << -1;
    } else {
        cout << result;
    }
}

// string s1, s2;
// int result = -1;

// set<string> g_set;

// void bfs(string s, int idx, int depth) {
//     queue<tuple<string, int, int>> q;

//     for(int i=0; i<s.size(); i++)
//         q.push({s, i, depth+1});

//     g_set.insert(s1);

//     while(q.size()) {
//         tie(s, idx, depth) = q.front(); q.pop();
//         if (idx == 0) {
//             s[idx] = (s[idx]=='0') ? '1' : '0';
//             s[idx+1] = (s[idx+1]=='0') ? '1' : '0';
//         } else if (idx == s.size()-1) {
//             s[idx] = (s[idx]=='0') ? '1' : '0';
//             s[idx-1] = (s[idx-1]=='0') ? '1' : '0';
//         } else {
//             s[idx] = (s[idx]=='0') ? '1' : '0';
//             s[idx-1] = (s[idx-1]=='0') ? '1' : '0';
//             s[idx+1] = (s[idx+1]=='0') ? '1' : '0';
//         }

//         if (s == s2) {
//             cout << depth;
//             exit(0);
//         }
        
//         if (g_set.count(s)) continue;

//         g_set.insert(s);
//         for(int i=0; i<s.size(); i++)
//             q.push({s, i, depth+1});
//     }
    
// }

// int main() {
//     int n; cin >> n;
//     cin >> s1 >> s2;

//     if (s1 == s2) {
//         cout << 0;
//         return 0;
//     }

//     bfs(s1, 0, 0);
//     cout << -1;
// }