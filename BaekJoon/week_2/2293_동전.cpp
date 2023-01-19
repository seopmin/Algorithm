#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n, k, input; cin >> n >> k;
  vector<int> dp(k+1);

  dp[0]=1;
  for(int i=0; i<n; i++){
    cin >> input;
    for(int j=input; j<=k; j++)
      dp[j] += dp[j-input];
  }
  cout << dp[k];
}



/*
int main() {
  int n, k, input; scanf("%d %d", &n, &k);
  int dp[10001] = {1};

  dp[0]=1;
  for(int i=0; i<n; i++){
    scanf("%d", &input);
    for(int j=input; j<=k; j++)
      dp[j] += dp[j-input];
  }
  printf("%d", dp[k]);
}



#include <stdio.h>
int main(){
	int n,k,x,dp[10001]={1};
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		for(int j=x;j<=k;++j)
			dp[j]+=dp[j-x];
	}
	printf("%d",dp[k]);
}
*/