#include<iostream>
#include<vector>
using namespace std;
int n, n2, bead, chu[31];
int dp[31][15001];

void DP(int i, int w){
	if (i > n || dp[i][w]) return;
	dp[i][w] = true;
	DP(i + 1, w + chu[i]);
	DP(i + 1, abs(w - chu[i]));
	DP(i + 1, w);
}

int main(){
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> chu[i];
	}
	DP(0, 0);

	cin >> n2;

	for (int i = 0; i < n2; i++){
		cin >> bead;

		if(bead > 15000) cout << "N ";
		else if (dp[n][bead]) cout << "Y ";
		else cout << "N ";
	}	
}


// int main() {
//   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//   int n1; cin >> n1; 
//   vector<int> chu(n1);
//   int sum =0;
//   for(int i=0; i<n1; i++) {
//     int w; cin >> w;
//     sum += w;
//     chu[i] = sum;
//   }

//   int n2; cin >> n2;
//   int i=0;
//   while(i<n2) {
//     int bead; cin >> bead;
//     for(int j=0; j<n1; j++) {
//       for(int w=j+1; w<n1; w++) {
//         if(chu[j]+bead == chu[w]-chu[j]) {
//           cout << "Y ";
//           goto point;
//         } else if(chu[j]+bead > chu[w]-chu[j]) {
//           continue;
//         } else {
//           break;
//         }
//       }
//     }
//     cout << "N ";
//     point:
//     i++;
//   }
// }



// int main() {
//   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//   int n1; cin >> n1;  // 추의 개수
//   // vector<pair<int, int>> chu(n1); // 추의 무게와, 추의 누적된 무게를 담음
//   vector<int> chu(n1);
//   int sum = 0;  // 모든 추의 총 무게
//   for(int i=0; i<n1; i++) {
//     int w; cin >> w;
//     sum += w;
//     chu[i] = sum;
//   }

//   int n2; cin >> n2;  // 구슬의 개수
//   int left, right, mid, bead;
//   int i=0;
//   point:
//   while(i<n2) {
//     cin >> bead;
//     left=0; right=n1-1;
//     point2:
//     while(left<=right) {
//       mid = (left+right)/2;
//       for(int j=mid+1; j<n1; j++) {
//         if(chu[mid]+bead == chu[j]-chu[mid]) {
//           cout << "Y ";
//           i++;
//           goto point; 
//         }
//         else if(chu[mid]+bead >chu[j]-chu[mid]) {
//           continue;
//         } else{
//           right = mid-1;
//           goto point2;
//         }
//         left = mid+1;
//       }



//       // if(chu[mid]+bead == sum-chu[mid]) {
//       //   cout << "Y ";
//       //   break;
//       // } else if(chu[mid]+bead > sum-chu[mid]) {
//       //   right = mid;
//       // } else {
//       //   left = mid+1;
//       // }
//     }
//     cout << "N ";
//     i++;
//   }
// }