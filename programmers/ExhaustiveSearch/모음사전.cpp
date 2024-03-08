#include <string>
#include <vector>

using namespace std;

string str;
int count = -1;
int answer;
string temp="AEIOU";

void dfs(string word) {
    count++;
    if (str == word) {
        answer = count;
        return;
    }
    
    if(word.size() >= 5) return;
    for(int i=0; i<temp.size(); i++) {
        dfs(word+temp[i]);
    }
}

int solution(string word) {
    str = word;
    dfs("");
    return answer;
}