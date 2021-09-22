#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, M;
int MAP[MAX][MAX], visited[MAX][MAX];
queue<pair<int, int>> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool allDone(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(MAP[i][j] != 0) continue;
            if(visited[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
int bfs(){
    int ret = 0;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N || MAP[ny][nx] != 0 || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            ret = max(ret, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
    if(allDone()) return ret;
    else return -1;
}
int main(){
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 1) q.push({i, j});
        }
    }
    cout << bfs() << "\n";
}