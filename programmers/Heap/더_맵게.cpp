#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for (int i=0; i<scoville.size(); i++)
        q.push(scoville[i]);  // 최소힙에 모두 넣기
    
    while (1) {
        if (q.top() >= K) break;
        if (q.size() < 2) return -1;  // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없음
        
        int first_lessSpicy = q.top(); q.pop();  // 첫번째로 덜 매운 음식
        int second_lessSpicy = q.top(); q.pop();  // 두번째로 덜 매운 음식
        int new_food = first_lessSpicy + (second_lessSpicy * 2);
        
        q.push(new_food);
        answer++;
    }
    
    return answer;
}