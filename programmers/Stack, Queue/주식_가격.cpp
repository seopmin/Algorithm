#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int discern=1;
    
    for (int i=0; i<prices.size(); i++) {
        discern=1;
        for (int j=i+1; j<prices.size(); j++) {
            if (prices[i] > prices[j]) {  // 주식 가격이 떨어지면
                answer.push_back(j-i);
                discern=0;
                break;
            }
        }
        if(discern) 
            answer.push_back(prices.size()-i-1);
        
    }
    
    return answer;
}