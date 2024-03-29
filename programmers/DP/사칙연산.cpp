#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> numbers;
vector<char> ops;

int func(int l, int r, int xn)
{
    if (l >= r) return numbers[l]; 
    
    // 최댓값을 구하는 경우: xn == 1
    int result;
    if (xn) {
        result = -987654321;
        for (int i=l; i<r; i++) {
            int lv, rv;
            lv = func(l, i-1, 1);
            
            if (ops[i] == '+')
                rv = func(i+1, r, 1);
            else
                rv = func(i+1, r, 0);
            
            if (ops[i] == '+') result = max(result, lv + rv);
            else result = max(lv-rv, result);
        }
    }
    
    // 최솟값을 구하는 경우
    else {
        result = 987654321;
        for (int i=l; i<r; i++) {
            int lv, rv;
            lv = func(l, i-1, 0);
            
            if (ops[i] == '+')
                rv = func(i+1, r, 0);
            else
                rv = func(i+1, r, 1);
            
            if (ops[i] == '+') result = min(result, lv + rv);
            else result = min(lv-rv, result);
        }
    }
    std::cout << l << ' ' << r << ' ' << xn << ' ' << result << std::endl;
    return result;
}

int solution(vector<string> arr)
{
    int answer = -1;
    
    for (int i=0; i<arr.size(); i++) {
        if (i%2==0) numbers.push_back(stoi(arr[i]));
        else ops.push_back(arr[i][0]);
    }
    
    return func(0, numbers.size()-1, 1);
}