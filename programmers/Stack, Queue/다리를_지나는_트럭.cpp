#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int truck_index=0;
    int total_weight=0;
    int seconds = 0;
    for (int i=0; i<bridge_length; i++) q.push(0);
    
    while(truck_index!=truck_weights.size()) {
        total_weight -= q.front();  // 다리에 있는 트럭이 나올 때 마다 무게를 빼줘야함.
        q.pop();
        
        if (total_weight + truck_weights[truck_index] > weight) {
            q.push(0);
        } else {
            q.push(truck_weights[truck_index]);
            total_weight += truck_weights[truck_index++];
        }
        seconds++;
    }
    return seconds+bridge_length;
}