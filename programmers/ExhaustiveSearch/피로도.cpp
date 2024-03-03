#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int result;  // 결과값
int visited[8];  // 방문 여부 확인

void dfs(int depth, int k, int index) {
    // 더이상 탐색할 dungeons가 없거나, k보다 소모 피로도가 더 클 경우 더이상 탐색하지 않음
    if (depth >= v.size() || k < v[index][0]) return;  
    
    result = max(result, depth+1);  // 최댓값 업데이트
    
    for(int i=0; i<v.size(); i++) {
        if (visited[i]) continue;  // 방문한 던전은 제외하고 탐색
    
        visited[i]=1;
        dfs(depth+1, k-v[index][1], i);
        visited[i]=0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    v = dungeons;
    for (int i=0; i<v.size(); i++) {
        visited[i] = 1;
        dfs(0, k, i);
        visited[i] = 0;
    }
    return result;
}