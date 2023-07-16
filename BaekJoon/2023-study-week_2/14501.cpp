#include<iostream>
#include<algorithm>
using namespace std;
int n, t[22], p[22], dp[22];

int main() {
	// 남은 일 수 N 입력
	cin >> n;
	// N일 동안의 상담 시간(t)과 수익(p) 입력
	for(int i=0; i<n; i++)
		cin >> t[i] >> p[i];

	// 뒤에서부터 동적 계획법을 사용하여 최대 수익 계산
	for(int i=n-1; i>=0; i--) {
		int pos=i+t[i]; // 해당 날짜에서 상담이 끝나는 위치 계산
		if(pos<=n)
			dp[i]=max(dp[pos]+p[i], dp[i+1]); // 해당 날짜에서 상담을 할 경우와 안 할 경우 중 최대 수익 선택
		else
			dp[i]=dp[i+1]; // 해당 날짜에서 상담을 할 수 없는 경우 다음 날의 최대 수익을 그대로 사용
	}
	// 최대 수익 출력
	cout << dp[0];
}