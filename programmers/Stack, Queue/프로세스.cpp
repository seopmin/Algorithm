#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq; // 우선순위 큐 생성
    queue<pair<int, int>> q; // (우선순위, 인덱스) 쌍을 저장하는 큐

    // 우선순위 큐와 인덱스 큐에 프로세스 정보 저장
    for (int i = 0; i < priorities.size(); ++i) {
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }

    while (!q.empty()) {
        int curPriority = q.front().first; // 현재 프로세스의 우선순위
        int curIndex = q.front().second; // 현재 프로세스의 인덱스
        q.pop();

        // 현재 프로세스보다 더 높은 우선순위가 있는지 확인
        if (pq.top() == curPriority) {
            pq.pop(); // 우선순위 큐에서도 제거
            answer++; // 실행 순서 증가
            // 만약 찾고자 하는 프로세스라면 반복 종료
            if (curIndex == location)
                break;
        } else {
            q.push({curPriority, curIndex}); // 우선순위가 더 높은 프로세스가 있으면 다시 큐에 넣기
        }
    }

    return answer;
}