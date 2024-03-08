#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int cnt;
vector<int> info[101];

void bfs(int v1, int v2) {
    queue<int> q;
    vector<int> visited(101);
    
    q.push(v1);
    visited[v1] = 1;
    visited[v2] = 1;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int i=0; i<info[node].size(); i++) {
            int node2 = info[node][i];
                                                 
            if (visited[node2]) continue;
            
            cnt++;
            q.push(node2);
            visited[node2] = 1;
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for (auto& wire: wires) {
        info[wire[0]].push_back(wire[1]);
        info[wire[1]].push_back(wire[0]);
    }
    
    for (auto& wire: wires) {
        cnt = 1;
        int v1 = wire[0];
        int v2 = wire[1];
       
        bfs(v1, v2);
        answer = min(answer, abs(2 * cnt - n));
   }
    
    return answer;
}