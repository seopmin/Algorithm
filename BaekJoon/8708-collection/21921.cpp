#include <iostream>
#include <algorithm>
using namespace std;

int sum, result, cnt, arr[250001];

int main() {
    int N, X; cin >> N >> X;

    for (int i=0; i<N; i++)
        cin >> arr[i];

    for (int i=0; i<X; i++)
        sum += arr[i];
    
    result = sum;
    cnt=1;

    for (int i=X; i<N; i++) {
        sum = sum + arr[i] - arr[i-X];
        if (result < sum) {
            cnt = 1;
            result = sum;
        } else if (result == sum) {
            cnt++;
        } 
    }

    if (!result) printf("SAD");
    else printf("%d\n%d\n", result, cnt);

}