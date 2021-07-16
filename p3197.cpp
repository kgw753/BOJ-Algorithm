#include<bits/stdc++.h>
using namespace std;
#define MAX 1500
int N, M, cnt;
string input;
vector<vector<char>> MAP(MAX, vector<char>(MAX));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<vector<int>> swanVisited(MAX, vector<int>(MAX, 0));
vector<pair<int, int>> swanPos;
queue<pair<int, int>> q;
queue<pair<int, int>> swanQ;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void melt(){
    queue<pair<int, int>> meltNext;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(MAP[y][x] == 'X') MAP[y][x] = '.';
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx]) continue;
            visited[ny][nx] = cnt;
            if(MAP[ny][nx] == '.') q.push(make_pair(ny, nx));
            else if(MAP[ny][nx] == 'X') meltNext.push(make_pair(ny, nx));
        }
    }
    q = meltNext;
}

bool meet(){
    queue<pair<int, int>> moveNext;
    bool ret = false;

    while(!swanQ.empty()){
        int y = swanQ.front().first;
        int x = swanQ.front().second;
        swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N || swanVisited[ny][nx]) continue;
            if(ny == swanPos[1].first && nx == swanPos[1].second){
                ret = true;
                break;
            }
            swanVisited[ny][nx] = 1;
            if(MAP[ny][nx] == 'X') moveNext.push(make_pair(ny, nx));
            else if(MAP[ny][nx] == '.') swanQ.push(make_pair(ny, nx));
        }
        if(ret) break;
    }
    swanQ = moveNext;
    return ret;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = input[j];
            if(MAP[i][j] == 'X') continue;
            visited[i][j] = 1;
            q.push(make_pair(i, j));
            if(MAP[i][j] == 'L') {
                swanPos.push_back(make_pair(i, j));
            }
        }
    }

    swanQ.push(swanPos[0]);
    swanVisited[swanPos[0].first][swanPos[0].second] = 1;

    while(true){
        melt();
        if(meet()) break;
        cnt++;
    }
    cout << cnt << "\n";
}