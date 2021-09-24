#include<bits/stdc++.h>
using namespace std;
#define MAX 304
int N, M, C;
int MAP[MAX][MAX], visited[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx] || !MAP[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}
int check(int y, int x){
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N || MAP[ny][nx]) continue;
        ret++;
    }
    return ret;
}
void melt(){
    memset(visited, 0, sizeof(visited));
    int tmp[MAX][MAX];
    memcpy(tmp, MAP, sizeof(tmp));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(tmp[i][j]){
                int n = check(i, j);
                tmp[i][j] = max(0, tmp[i][j] - n);
            }
        }
    }
    memcpy(MAP, tmp, sizeof(tmp));
}
int counter(){
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(MAP[i][j] && visited[i][j] == 0) {
                visited[i][j] = 1;
                bfs(i, j);
                cnt++;
            }
        }
    }
    if(C == 0) C = cnt;
    return cnt;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
        }
    }
    int year = 0;
    while(counter() == C){
        melt();
        year++;
    }
    if(counter()) cout << year << "\n";
    else cout << 0 << "\n";
}