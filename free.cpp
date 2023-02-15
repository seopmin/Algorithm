#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int a, p;
int visited[1000000] = {0, };
int depth[1000000] = {0, };
int result = 0;

int getSum(int val, int p_){
    int res = 0;

    // // 문자열 분리 활용
    // string str = to_string(val);
    // for(int i=0; i<str.size(); i++){
    //     res += pow(str[i] - '0', p_);
    // }
    int tmp = val;

    for(int i = 0; i < to_string(val).size(); i++){
        // tmp 사용하지 않고 val 넣으면, 반복문 조건이 바뀌므로 오답
        res += pow((tmp % 10), p_);
        tmp /= 10;
    }

    return res;
}

int DFS(int val, int p_, int dep){
    // val = d(1)부터 시작. 수열 d의 값들.
    // dep = 이전 노드의 depth
    
    ++visited[val];

    if(visited[val] >= 2){ // 종료조건
        return depth[val] - 1;
        // return;
    }

    depth[val] = dep + 1;

    int next_val = getSum(val, p_);
    return DFS(next_val, p_, depth[val]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>p;

    cout << DFS(a, p, 0);
    // cout << result;

    return 0;
}