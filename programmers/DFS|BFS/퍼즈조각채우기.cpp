#include <string>
#include <vector>
#include <queue>
#include <string.h>


using namespace std;

int visited[51][51];
vector<vector<pair<int, int>>> pieces;
vector<vector<pair<int, int>>> blanks;


// 90도 회전
vector<vector<int>> rotate(vector<vector<int>>& map) {
    int c = map.size();
    int r = map[0].size();
    
    vector<vector<int>> temp;
    vector<int> row(r);
    
    for(int i=0; i<c; i++) temp.push_back(row);
    
    for(int i=0; i<map.size(); i++) {
        for(int j=0; j<map[i].size(); j++) {
            temp[map.size()-j-1][i] = map[i][j];
        }
    }
    
    return temp;
}


// 해당 piece의 좌표 정보 담아서 리턴
vector<pair<int, int>> getPiece(int x,int y, vector<vector<int>>& select){
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    
    queue<pair<int ,int>> q;
    vector<pair<int, int>> list;
    visited[x][y] = true;
    q.push({x, y});
    list.push_back({x, y});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= select.size() || ny >= select.size() 
            || visited[nx][ny] || !select[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx,ny});
            list.push_back({nx,ny});
        }
    }
    return list;
}


// (0, 0) 으로 맞추기
vector<pair<int, int>> rePos(vector<pair<int, int>> p){
    int minX = p[0].first;
    int minY = p[0].second;

    for(int i = 1; i < p.size(); i++){
        minX = min(minX,p[i].first);
        minY = min(minY,p[i].second);
    }

    for(int i = 0; i < p.size(); i++){
        p[i].first -= minX;
        p[i].second -= minY;
    }
    return p;
}

// 두 퍼즐이 일치하는지 비교하는 함수
int comparePiece(vector<pair<int, int>> a, vector<pair<int, int>> b){
    int answer = 0;
    a = rePos(a);
    b = rePos(b);

    int count = 0;
    // 애초에 개수가 일치하지 않으면 틀림
    if(a.size() != b.size()) return 0;

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i].first == b[j].first && a[i].second == b[j].second){
                count++;
                break;
            }
        }
    }
    // 일치하는 좌표의 개수가 같을 때만 맞음
    if(count == a.size()) return a.size();
    else return 0;
}

// 다시 방문하지 않도록 빈 공간 메우기
vector<vector<int>> fillBoard(vector<pair<int, int>> p, vector<vector<int>> board){
    for(int i = 0; i < p.size(); i++){
        int x = p[i].first;
        int y = p[i].second;
        board[x][y] = false;
    }
    return board;
}



int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    for(int i=0; i<table.size(); i++) {
        for(int j=0; j<table.size(); j++) {
            game_board[i][j] = !game_board[i][j];
        }
    }
    
    
    for(int i = 0; i < table.size(); i++)
        for(int j = 0; j < table[i].size(); j++)
            if(!visited[i][j] && table[i][j]) pieces.push_back(getPiece(i,j,table));
    
    int cnt=4;
    
    memset(visited, 0, sizeof(visited));
    
    while(cnt--) {
        for(int i=0; i<game_board.size(); i++) {
            for(int j=0; j<game_board.size(); j++) {
                if(game_board[i][j] && !visited[i][j]) blanks.push_back(getPiece(i, j, game_board));
            }
        }
        for(int i=0; i<pieces.size(); i++) {
            for(int j=0; j<blanks.size(); j++) {
                int k = comparePiece(pieces[i], blanks[j]);
                if(k) {
                    answer += k;
                    game_board = fillBoard(blanks[j], game_board);
                    pieces.erase(pieces.begin()+i);
                    blanks.erase(blanks.begin()+j);
                    i--;
                    break;
                }
            }
        }
        game_board = rotate(game_board);
        memset(visited, 0, sizeof(visited));
    }
    
    return answer;
}