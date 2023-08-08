#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//  U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면
/*초기 큐브 세팅*/
// 윗면: w, 아랫면: y, 앞 면, r, 뒷 면: o, 왼쪽 면: g, 오른쪽 면: b
int tc, n;
string s;
char basic_cube[6][3][3]={
	{{'w','w','w'},{'w','w','w'},{'w','w','w'}},
	{{'y','y','y'},{'y','y','y'},{'y','y','y'}},
	{{'o','o','o'},{'o','o','o'},{'o','o','o'}},
	{{'r','r','r'},{'r','r','r'},{'r','r','r'}},
	{{'g','g','g'},{'g','g','g'},{'g','g','g'}},
	{{'b','b','b'},{'b','b','b'},{'b','b','b'}}
};

char cube[6][3][3];

// 사이드에 붙어있는 큐브 세팅
void setting_2(int pos, int dir) {
	char t1, t2, t3;
	if(pos==0) {
		if(dir==1) {
			t1=cube[2][0][0], t2=cube[2][0][1], t3=cube[2][0][2];
			cube[2][0][0]=cube[4][0][0], cube[2][0][1]=cube[4][0][1], cube[2][0][2]=cube[4][0][2];
			cube[4][0][0]=cube[3][0][0], cube[4][0][1]=cube[3][0][1], cube[4][0][2]=cube[3][0][2];
			cube[3][0][0]=cube[5][0][0], cube[3][0][1]=cube[5][0][1], cube[3][0][2]=cube[5][0][2];
			cube[5][0][0]=t1, cube[5][0][1]=t2, cube[5][0][2]=t3;
		} else {
			t1=cube[2][0][0], t2=cube[2][0][1], t3=cube[2][0][2];
			cube[2][0][0]=cube[5][0][0], cube[2][0][1]=cube[5][0][1], cube[2][0][2]=cube[5][0][2];
			cube[5][0][0]=cube[3][0][0], cube[5][0][1]=cube[3][0][1], cube[5][0][2]=cube[3][0][2];
			cube[3][0][0]=cube[4][0][0], cube[3][0][1]=cube[4][0][1], cube[3][0][2]=cube[4][0][2];
			cube[4][0][0]=t1, cube[4][0][1]=t2, cube[4][0][2]=t3;
		}
	} else if(pos==1) {
		if(dir==1) {
			t1=cube[2][2][0], t2=cube[2][2][1], t3=cube[2][2][2];
			cube[2][2][0]=cube[5][2][0], cube[2][2][1]=cube[5][2][1], cube[2][2][2]=cube[5][2][2];
			cube[5][2][0]=cube[3][2][0], cube[5][2][1]=cube[3][2][1], cube[5][2][2]=cube[3][2][2];
			cube[3][2][0]=cube[4][2][0], cube[3][2][1]=cube[4][2][1], cube[3][2][2]=cube[4][2][2];
			cube[4][2][0]=t1, cube[4][2][1]=t2, cube[4][2][2]=t3;
		} else {
			t1=cube[2][2][0], t2=cube[2][2][1], t3=cube[2][2][2];
			cube[2][2][0]=cube[4][2][0], cube[2][2][1]=cube[4][2][1], cube[2][2][2]=cube[4][2][2];
			cube[4][2][0]=cube[3][2][0], cube[4][2][1]=cube[3][2][1], cube[4][2][2]=cube[3][2][2];
			cube[3][2][0]=cube[5][2][0], cube[3][2][1]=cube[5][2][1], cube[3][2][2]=cube[5][2][2];
			cube[5][2][0]=t1, cube[5][2][1]=t2, cube[5][2][2]=t3;
		}
	} else if(pos==2) {
		if(dir==1) {
			t1=cube[0][0][2], t2=cube[0][0][1], t3=cube[0][0][0];
			cube[0][0][2]=cube[5][2][2], cube[0][0][1]=cube[5][1][2], cube[0][0][0]=cube[5][0][2];
			cube[5][2][2]=cube[1][2][2], cube[5][1][2]=cube[1][2][1], cube[5][0][2]=cube[1][2][0];
			cube[1][2][2]=cube[4][0][0], cube[1][2][1]=cube[4][1][0], cube[1][2][0]=cube[4][2][0];
			cube[4][0][0]=t1, cube[4][1][0]=t2, cube[4][2][0]=t3;
		} else {
			t1=cube[0][0][2], t2=cube[0][0][1], t3=cube[0][0][0];
			cube[0][0][2]=cube[4][0][0], cube[0][0][1]=cube[4][1][0], cube[0][0][0]=cube[4][2][0];
			cube[4][0][0]=cube[1][2][2], cube[4][1][0]=cube[1][2][1], cube[4][2][0]=cube[1][2][0];
			cube[1][2][2]=cube[5][2][2], cube[1][2][1]=cube[5][1][2], cube[1][2][0]=cube[5][0][2];
			cube[5][2][2]=t1, cube[5][1][2]=t2, cube[5][0][2]=t3;
		}
	} else if(pos==3) {
		if(dir==1) {
			t1=cube[0][2][2], t2=cube[0][2][1], t3=cube[0][2][0];
			cube[0][2][2]=cube[4][0][2], cube[0][2][1]=cube[4][1][2], cube[0][2][0]=cube[4][2][2];
			cube[4][0][2]=cube[1][0][2], cube[4][1][2]=cube[1][0][1], cube[4][2][2]=cube[1][0][0];
			cube[1][0][2]=cube[5][2][0], cube[1][0][1]=cube[5][1][0], cube[1][0][0]=cube[5][0][0];
			cube[5][2][0]=t1, cube[5][1][0]=t2, cube[5][0][0]=t3;
		} else {
			t1=cube[0][2][2], t2=cube[0][2][1], t3=cube[0][2][0];
			cube[0][2][2]=cube[5][2][0], cube[0][2][1]=cube[5][1][0], cube[0][2][0]=cube[5][0][0];
			cube[5][2][0]=cube[1][0][2], cube[5][1][0]=cube[1][0][1], cube[5][0][0]=cube[1][0][0];
			cube[1][0][2]=cube[4][0][2], cube[1][0][1]=cube[4][1][2], cube[1][0][0]=cube[4][2][2];
			cube[4][0][2]=t1, cube[4][1][2]=t2, cube[4][2][2]=t3;
		}
	} else if(pos==4) {
		if(dir==1) {
			t1=cube[0][2][0], t2=cube[0][1][0], t3=cube[0][0][0];
			cube[0][2][0]=cube[2][0][2], cube[0][1][0]=cube[2][1][2], cube[0][0][0]=cube[2][2][2];
			cube[2][0][2]=cube[1][2][2], cube[2][1][2]=cube[1][1][2], cube[2][2][2]=cube[1][0][2];
			cube[1][2][2]=cube[3][2][0], cube[1][1][2]=cube[3][1][0], cube[1][0][2]=cube[3][0][0];
			cube[3][2][0]=t1, cube[3][1][0]=t2, cube[3][0][0]=t3;
		} else {
			t1=cube[0][2][0], t2=cube[0][1][0], t3=cube[0][0][0];
			cube[0][2][0]=cube[3][2][0], cube[0][1][0]=cube[3][1][0], cube[0][0][0]=cube[3][0][0];
			cube[3][2][0]=cube[1][2][2], cube[3][1][0]=cube[1][1][2], cube[3][0][0]=cube[1][0][2];
			cube[1][2][2]=cube[2][0][2], cube[1][1][2]=cube[2][1][2], cube[1][0][2]=cube[2][2][2];
			cube[2][0][2]=t1, cube[2][1][2]=t2, cube[2][2][2]=t3;
		}
	} else if(pos==5) {
		if(dir==1) {
			t1=cube[0][2][2], t2=cube[0][1][2], t3=cube[0][0][2];
			cube[0][2][2]=cube[3][2][2], cube[0][1][2]=cube[3][1][2], cube[0][0][2]=cube[3][0][2];
			cube[3][2][2]=cube[1][2][0], cube[3][1][2]=cube[1][1][0], cube[3][0][2]=cube[1][0][0];
			cube[1][2][0]=cube[2][0][0], cube[1][1][0]=cube[2][1][0], cube[1][0][0]=cube[2][2][0];
			cube[2][0][0]=t1, cube[2][1][0]=t2, cube[2][2][0]=t3;
		} else {
			t1=cube[0][2][2], t2=cube[0][1][2], t3=cube[0][0][2];
			cube[0][2][2]=cube[2][0][0], cube[0][1][2]=cube[2][1][0], cube[0][0][2]=cube[2][2][0];
			cube[2][0][0]=cube[1][2][0], cube[2][1][0]=cube[1][1][0], cube[2][2][0]=cube[1][0][0];
			cube[1][2][0]=cube[3][2][2], cube[1][1][0]=cube[3][1][2], cube[1][0][0]=cube[3][0][2];
			cube[3][2][2]=t1, cube[3][1][2]=t2, cube[3][0][2]=t3;
		}
	}
}

// pos: cube에 돌릴 면의 index 위치, dir: 방향 1(오른쪽) -1(왼쪽)
void setting_1(int pos, int dir) {
  if(pos==1) dir=dir*-1;

	if(dir==1) {  //오른쪽으로 회전
		for(int i=0; i<3; i++) {
			for(int j=i; j<3; j++) {
				swap(cube[pos][i][j], cube[pos][j][i]);
			}
		}
		for(int i=0; i<3; i++) {
			for(int j=0; j<3/2; j++) {
				swap(cube[pos][i][j], cube[pos][i][3-j-1]);
			}
		}
	} else if(dir==-1) {  // 왼쪽으로 회전
		for(int i=0; i<3; i++) {
			for(int j=i; j<3; j++) {
				swap(cube[pos][i][j], cube[pos][j][i]);
			}
		}
		for(int j=0; j<3; j++) {
			for(int i=0; i<3/2; i++) {
				swap(cube[pos][i][j], cube[pos][3-i-1][j]);
			}
		}
	}
  if(pos==1) dir=dir*-1;
	setting_2(pos, dir);
}

void init_cube() {
	for(int i=0; i<6; i++) {
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) {
				cube[i][j][k]=basic_cube[i][j][k];
			}
		}
	}
}

int main() {
	cin >> tc;
	while(tc--) {
		cin >> n;
		init_cube();
		for(int i=0; i<n; i++) {
			cin >> s;
			int pos;
			if(s[0]=='U')
				pos=0;
			else if(s[0]=='D')
				pos=1;
		  else if(s[0]=='F')
				pos=3;
			else if(s[0]=='B')
				pos=2;
			else if(s[0]=='L')
				pos=4;
			else if(s[0]=='R')
				pos=5;
			
			if(s[1]=='+') setting_1(pos, 1);
			else setting_1(pos, -1);
		}
    
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				cout << cube[0][i][j];
      }
			cout << endl;
    }
	}
}

/*
1
7
D+ L- B- U+ D+ B+ B+
*/
/*
yyb
wwg
wwg
*/