// spread 차원 배열을 따로 둔 이유 -> 확산은 동시에 일어나기 때문에 바로 맵에 더해주면 동시가 아니게 됨.
// -> 따라서 확산된 미세먼지를 따로 담아두어 모두 확산이 일어난 뒤 맵에 확산된 미세먼지를 더해줌

#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int r, c, t, a[51][51], spread[51][51], pos_t, pos_b;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void func2(int x, int y) {  // 확산되는 미세먼지를 구하는 함수
	int sp = a[y][x]/5, cnt=0;
	for(int i=0; i<4; i++) {
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || ny<0 || nx>=c || ny>=r || a[ny][nx]==-1) continue;
		cnt++;
		spread[ny][nx]+=sp;
	}
	a[y][x] -= cnt*sp;
}

void func() {  // 해당 위치에 미세먼지가 있는지 확인하는 함수
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(a[i][j]==-1 || a[i][j]==0) continue;
			func2(j, i);
		}
	}
}

void sum_f() {  // 확산된 미세먼지를 해당 맵에 더하는 함수
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(a[i][j]==-1) continue;
			a[i][j] += spread[i][j];
		}
	}
}

void clean_f() {  // 미세먼지를 청소하는 함수
	for(int i=pos_t; i>=0; i--)
		a[i][0]=a[i-1][0];
	
	for(int i=pos_b; i<r; i++)
		a[i][0]=a[i+1][0];

	for(int i=0; i<c; i++) {
		a[0][i] = a[0][i+1];
		a[r-1][i] = a[r-1][i+1];
	}

	for(int i=0; i<pos_t; i++)
		a[i][c-1]=a[i+1][c-1];

	for(int i=r-1; i>pos_b; i--) 
		a[i][c-1]=a[i-1][c-1];

	for(int i=c-1; i>1; i--) {
		a[pos_t][i]=a[pos_t][i-1];
		a[pos_b][i]=a[pos_b][i-1];
	}
	a[pos_t][1]=0;
	a[pos_b][1]=0;
}

int main() {
	cin >> r >> c >> t;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> a[i][j];
			if(a[i][j]==-1) pos_b=i;
		}
	}
	pos_t = pos_b-1;

	for(int i=0; i<t; i++) {
		func();
		sum_f();
		memset(spread, 0, sizeof(spread));
		clean_f();
		a[pos_b][0]=-1, a[pos_t][0]=-1;
	}

	long long result=0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(a[i][j]==-1) continue;
			result += a[i][j];
		}
	}

	cout << result;
}