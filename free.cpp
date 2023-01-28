// 팰린드롬 만들기

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int arr[5001];
int dp[2500][2500];

int sol(int l, int r){ // right index, left index
    if(l >= r){
        return 0;
    }
    
    if(dp[l][r] != -1){
        return dp[l][r];
    }

    if(arr[l] == arr[r]){
        dp[l][r] = sol(l+1, r-1);
    }
    else{
        dp[l][r] = (1 + min(sol(l+1, r), sol(l, r-1)));
    }

    return dp[l][r];

}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans = sol(0, n-1);
    cout<< ans << endl;

    return 0;
}