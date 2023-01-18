#include <iostream>
#include <string>

using namespace std;

int n, m;
long long ans;
char broken[11];

int check(string num){
    for(int i=0; i<m; i++){
        for(int j=0; j<num.length(); j++){
            if(num[j] == broken[i]){ // 고장난 버튼 포함된 경우
                return 0;
            }
        }
    }

    return 1;
}

int findNearby_low(){
    for(int i = n; i>=0; i--){
        if(check(to_string(i)) == 1){
            return i;
        }
    }

}

int findNearby_high(){
    for(int i = n; i < n + abs(n - 100); i++){
    // abs(n-100) 사용한 이유: 100과의 거리보다 멀면 그냥 100에서 + 계속 쓰는 것이 빠름
        if(check(to_string(i)) == 1){
            return i;
        }
    }
}


int main(){

    
    cin >>n; cin>>m;
    for(int i=0; i<m; i++){
        cin>>broken[i];
    }

    string num = to_string(n);

    if(check(num) == 1){ // 고장난 버튼 포함 X
        ans = num.length();


    }
    else{ // 고장난 버튼 포함 O
        int nearby;
        int h = findNearby_high();
        int l = findNearby_low();
        if(h - n > n - l){
            nearby = l;
        }
        else{
            nearby = h;
        }

        ans = num.length() + abs(nearby - n);
    }

    if(ans > abs(n - 100)){
        ans = abs(n - 100);
    }

    if(n == 100){
        ans = 0;
    }

    

    cout << ans << "\n";
    
    return 0;
}