#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt=0;

    priority_queue<int> pq; 
    priority_queue<int, vector<int>, greater<int>> pq2; 
    char c; int n;
    for(int i=0;i<operations.size();i++)
    {
        stringstream ss(operations[i]);
        ss >> c;
        ss >> n;
        if(cnt == 0)
        {
            while(!pq.empty()) pq.pop();
            while(!pq2.empty()) pq2.pop();
        }
        if(c == 'I'){
            pq.push(n);
            pq2.push(n);
            cnt++;
        }else{
            if(n == 1 and cnt != 0){
                pq.pop();
                cnt--;
            }else if(n == -1 and cnt != 0){
                pq2.pop();
                cnt--;
            }
        }
    }
    if(cnt == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(pq.top());
        answer.push_back(pq2.top());
    }
    return answer;
}