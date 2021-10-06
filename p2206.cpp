#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, M;
int MAP[MAX][MAX];
int visited[MAX][MAX][2];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(int y, int x){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{y, x}, {0, 1}});
    visited[y][x][0] = 1;
    int b, cnt;
    while(q.size()){
        y = q.front().first.first;
        x = q.front().first.second;
        b = q.front().second.first;
        cnt = q.front().second.second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(MAP[ny][nx]){
                if(b == 0){
                    visited[ny][nx][1] = cnt + 1;
                    q.push({{ny, nx}, {1, cnt + 1}});
                }
                else{
                    continue;
                }
            }
            else{
                if(visited[ny][nx][b] == 1e9){
                    visited[ny][nx][b] = cnt + 1;
                    q.push({{ny, nx}, {b, cnt + 1}});
                }
            }
        }
    }
}
int main(){
    cin >> N >> M;
    string input;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = input[j] - '0';
        }
    }
    fill(&visited[0][0][0], &visited[MAX - 1][MAX][1], 1e9);
    bfs(0, 0);
    int res = min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]);
    if(res == 1e9) cout << -1 << "\n";
    else cout << res << "\n";
}