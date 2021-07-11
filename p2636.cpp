#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> tmp(MAX, vector<int>(MAX, 0));
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
vector<pair<int, int>> pos;
int hours, cheese;
int N, M, sx, sy;

void counter(int y, int x){
    visited[y][x] = true;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(visited[ny][nx] == false && MAP[ny][nx] == 1) counter(ny, nx);
    }
}
void melt(int y, int x, int dir){
    if(tmp[y][x] == 1) cheese--;
    tmp[y][x] = 0;
    visited[y][x] = true;
    for(int i = 0; i < 8; i++, dir++){
        int nx = x + dx[dir % 8];
        int ny = y + dy[dir % 8];
        if(ny == sy && nx == sx) return;
        if(MAP[ny][nx] == 1){
            melt(ny, nx, (dir - 2 + 8) % 8);
            return;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 1) cheese++;
        }
    }

    int prev;
    while(cheese > 0){
        prev = cheese;
        hours++;
        
        for(int i = 0; i < N; i++) fill(visited[i].begin(), visited[i].begin() + M, false);
        pos.clear();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(MAP[i][j] == 1 && visited[i][j] == false){
                    counter(i, j);
                    pos.push_back(make_pair(i, j));
                }
            }
        }
        for(int i = 0; i < N; i++) fill(visited[i].begin(), visited[i].begin() + M, false);
        for(int i = 0; i < pos.size(); i++){
            sy = pos[i].first;
            sx = pos[i].second;
            tmp = MAP;
            melt(sy, sx, 0);
            MAP = tmp;
        }
    }

    cout << hours << "\n";
    cout << prev << "\n";
}