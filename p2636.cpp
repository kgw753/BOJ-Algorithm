#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, M, sy, sx, hour, cnt;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> tmp(MAX, vector<int>(MAX, 0));
queue<pair<int, int>> pos;
void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void go(int y, int x, int dir){
    if(tmp[y][x]) cnt--;
    tmp[y][x] = 0;
    for(int i = 0; i < 8; i++, dir++){
        int nx = x + dx[dir % 8];
        int ny = y + dy[dir % 8];
        if(sx == nx && sy == ny) return;
        if(MAP[ny][nx]){
            go(ny, nx, (dir - 2 + 8) % 8);
            return;
        }
    }
}
void counter(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(MAP[ny][nx] && visited[ny][nx] == 0) counter(ny, nx);
    }
}
void melt(){
    for(int i = 0; i < N; i++) fill(visited[i].begin(), visited[i].end(), 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(MAP[i][j] == 1 && visited[i][j] == 0) {
                pos.push({i, j});
                counter(i, j);
            }
        }
    }
    while(pos.size()){
        sy = pos.front().first;
        sx = pos.front().second;
        pos.pop();
        tmp = MAP;
        go(sy, sx, 6);
        MAP = tmp;
    }
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 1) cnt++;
        }
    }
    int prev;
    while(cnt > 0){
        prev = cnt;
        hour++;
        melt();
    }
    cout << hour << "\n" << prev << "\n";
}