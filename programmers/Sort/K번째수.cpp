#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto iter = commands.begin(); iter != commands.end(); iter++){
        vector<int> copy_array = {array.begin(), array.end()};
        int i = (*iter)[0]; int j = (*iter)[1]; int k = (*iter)[2];
        sort(&copy_array[i-1], &copy_array[j-1]+1);
        answer.push_back(copy_array[i+k-2]);
    }
    return answer;
}